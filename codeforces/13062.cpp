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

ll dp[101][101];
double tdp[101][101];
bool memo[101][101];
ll cnt;

ll solve(int i, int j)
{
	if(j==0)
		return 1;
	if(memo[i][j])
		return dp[i][j];
	ll &ret=dp[i][j]=1;
	if(i>0)
		ret*=solve(i-1, j);
	if(j>0)
		ret*=solve(i+1, j-1);
	memo[i][j]=true;
	return ret;
}

double trace(int i, int j)
{
	if(j==0)
	{
		if(i==0)
			return 1;
		return (double)(1.0*cnt)/(1.0*i);
	}
	if(memo[i][j])
		return tdp[i][j];
	double &ret=tdp[i][j]=0;
	if(i>0)
		ret+=trace(i-1, j);
	if(j>0)
		ret+=trace(i+1, j-1);
	memo[i][j]=true;
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
	init();
	ll x, y;
	while(scanf("%lld %lld", &x, &y) && (x+y))
	{
		RESET(memo, false);
		cnt=solve(x, y);
		printf("#%d\n", cnt);

		RESET(memo, false);
		printf("%.5f\n", trace(x,y));
	}
	return 0;
}