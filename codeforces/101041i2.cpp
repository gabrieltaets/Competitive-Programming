/// David Mateus Batista <david.batista3010@gmail.com>
/// Computer Science - Federal University of Itajuba - Brazil

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define PI (double)acos(-1.0)
#define RAD(x) (double)(x*PI)/180.0
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define D(x) x&(-x)
#define reset(a, b) memset(a, b, sizeof(a))
#define debug(x,y) cout << x << y << endl
#define gcd(x,y) __gcd(x, y)
#define lcm(x,y) (x*y)/gcd(x,y)
#define bitcount(x) __builtin_popcount(x)

int mi[] = {0, -1, 0, 1, -1, 1, 1, -1};
int mj[] = {1, 0, -1, 0, 1, 1, -1, -1};

const int MN=100000+35;
int v[MN], t[MN];
int n, k;
int dp[MN][501][2];

int solve(int i, int q, int h)
{
	if(i==n-1)
		return h*(v[i]+t[i]);
	if(dp[i][q][h]!=-1)
		return dp[i][q][h];
	int &ret=dp[i][q][h]=0;
	if(h)
	{
		ret=max(ret, v[i]+t[i]+solve(i+1, q, 0));
		ret=max(ret, solve(i+1, q, 1));
		if(q+1<=k)
			ret=max(ret, t[i]+solve(i+1, q+1, 1));
	}
	else
	{
		if(q+1<=k)
			ret=max(ret, -v[i]+solve(i+1, q+1, 1));
		ret=max(ret, solve(i+1, q, 0));
	}
	return ret;
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
  cout << sizeof dp << endl;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d", &v[i]);
	for(int i=1; i<n; i++)
		scanf("%d", &t[i]);
	reset(dp, -1);
	printf("%d\n", solve(0,0,0));
 	return 0;
}