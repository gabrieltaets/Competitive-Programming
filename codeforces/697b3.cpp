/// David Mateus Batista <david.batista3010@gmail.com>
/// Computer Science - Federal University of Itajuba - Brazil

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

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
#define ALL(x) ((x.begin(), (x.end())))
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
	string str;
	cin >> str;

	string aux;
	bool flag=false;
	int v=0;

	int r=-1;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='e')
		{
			r=i;
			flag=true;
		}
		else if(flag)
			v=v*10+str[i]-'0';
	}

	if(r!=-1)
		str.erase(str.begin()+r, str.end());
	for(int i=0; i<str.size()-1 && v; i++)
	{
		if(str[i]=='.')
		{
			swap(str[i], str[i+1]);
			v--;
		}
	}

	if(str[str.size()-1]=='.')
	{
		str.erase(str.size()-1, 1);
		if(str[0]=='0')
			str.erase(0, 1);
	}
	while(v)
	{
		str.pb('0');
		v--;
	}
	while(str[0]=='0' && str[1]!='.')
		str.erase(0,1);
	cout << str << endl;
	return 0;
}