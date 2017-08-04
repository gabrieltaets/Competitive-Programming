/// David Mateus Batista <david.batista3010@gmail.com>
/// Computer Science - Federal University of Itajuba - Brazil

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define PI (double)acos(-1.0)
#define RAD(x) (double)(x*PI)/180.0
#define PCT(x,y) (double)x*100.0/y
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define D(x) x&(-x)
#define ALL(x) x.begin(),x.end()
#define RESET(a,b) memset(a, b, sizeof(a))
#define DEBUG(x,y) cout << x << y << endl
#define gcd(x,y) __gcd(x, y)
#define lcm(x,y) (x/gcd(x,y))*y
#define bitcnt(x) __builtin_popcountll(x)
#define lbit(x) 63-__builtin_clzll(x)
#define zerosbitll(x) __builtin_ctzll(x)
#define zerosbit(x) __builtin_ctz(x)

enum {North, East, South, West};
//{0, 1, 2, 3}
//{Up, Right, Down, Left}

int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};

class aho_corasick
{
private:
	static const int MNT=600;
	static const int MNC=30;
public:
	int trie[MNT][MNC];
	int term[MNT];
	int link[MNT];
	int pos[15][MNT];
	int cnt=1;
	aho_corasick(){};
	void clear()
	{
		RESET(trie, 0);
		RESET(pos, 0);
		RESET(term, 0);
		RESET(link, 0);
		cnt=1;
	}
	int node(int x, int j)
	{
		return trie[x][j];
	}
	int end(int x, int j)
	{
		return term[ node(x,j) ];
	}
	void insert(char *str, int p)
	{
		int sz=strlen(str);
		int no=0;
		for(int i=0; i<sz; i++)
		{
			int x=str[i]-'a';
			if(!trie[no][x])
				trie[no][x]=cnt++;
			pos[p][ trie[no][x] ]=i;
			no=trie[no][x];
		}
		term[no]|=(1<<p);
	}
	void update_link()
	{
		queue<int>aho;
		aho.push(0);
		while(!aho.empty())
		{
			int x=aho.front();
			aho.pop();
			term[x]|=term[ link[x] ];
			for(int i=0; i<MNC; i++)
			{
				if(trie[x][i])
				{
					int y=trie[x][i];
					aho.push(y);
					link[y]=x?trie[ link[x] ][i]:0;
				}
				else
				{
					trie[x][i]=trie[ link[x] ][i];
				}
			}
		}
	}
};

aho_corasick aho;
int n, m;

char buffer[600];
int tam[16];
char data[16][600];

bool memo[1<<16][600];
int dp[1<<16][600];
int solve(int mask, int p)
{
	if(mask>=(1<<n))
		return INF;
	if(mask==(1<<n)-1)
		return 0;
	if(memo[mask][p])
		return dp[mask][p];
	int &ret=dp[mask][p]=INF;
	for(int i=0; i<n; i++)
	{
		if(!(mask&(1<<i)))
		{
			bool flag=true;
			int v=p;
			int mx=0;
			int cnt=0;
			for(int j=aho.pos[i][p]; j<tam[i] && flag; j++)
			{
				cnt++;
				mx|=aho.end(v, data[i][j]-'a');
				v=aho.node(v, data[i][j]-'a');
				if(mx>=(1<<n))
					flag=false;
				if(mx&(1<<i))
					break;
			}
			if(flag && mx)
				ret=min(ret, cnt+solve(mask|mx, v));
		}
	}
	memo[mask][p]=true;
	return ret;
}

string ans;
void trace(int mask, int p)
{
	if(mask==(1<<n)-1)
		return;
	int ret=INF;
	int lpx=0, rpx=0, px=0, vx=0, mxx=0;
	for(int i=0; i<n; i++)
	{
		if(!(mask&(1<<i)))
		{
			bool flag=true;
			int v=p;
			int r=0;
			int mx=0;
			int cnt=0;
			for(int j=aho.pos[i][p]; j<tam[i] && flag; j++)
			{
				r=max(r, j);
				cnt++;
				mx|=aho.end(v, data[i][j]-'a');
				v=aho.node(v, data[i][j]-'a');
				if(mx>=(1<<n))
					flag=false;
				if(mx&(1<<i))
					break;
			}
			if(flag && mx)
			{
				if(ret>cnt+solve(mask|mx, v))
				{
					ret=cnt+solve(mask|mx, v);
					px=i;
					lpx=aho.pos[i][p];
					rpx=r;
					vx=v;
					mxx=mx;
				}
			}
		}
	}
	for(int i=lpx; i<=rpx; i++)
		ans.pb( data[px][i] );
	trace(mask|mxx, vx);
}

void init()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cout << "[FREOPEN]" << endl;
	return;
}

int main()
{
	//init();
	aho.clear();
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
	{
		scanf("%s", data[i]);
		tam[i]=strlen(data[i]);
		aho.insert(data[i], i);
	}

	for(int i=0; i<m; i++)
	{
		scanf("%s", buffer);
		aho.insert(buffer, n+i);
	}
	aho.update_link();
	int v=solve(0, 0);
	//printf("#%d\n", v);
	if(v==INF)
		printf("-\n");
	else
	{
		trace(0, 0);
		if(ans.size()==0)
			printf("-\n");
		else
			printf("%s\n", ans.c_str());
	}
}