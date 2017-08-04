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

struct node
{
	ll a, b, c;
	node(){};
	node(ll _a, ll _b, ll _c)
	{
		a=_a, b=_b, c=_c;
	}
};


ll A[3][3]={-1, 2, 2, -2, 1, 2, -2, 2, 3};
ll B[3][3]={1, 2, 2, 2, 1, 2, 2, 2, 3};
ll C[3][3]={1, -2, 2, 2, -1, 2, 2, -2, 3};

vector<node>data;

void solve(ll x)
{
	if(x<=2)
	{
		printf("-1\n");
		return;
	}
	ll aux[3];
	aux[0]=x;
	aux[1]=(x*x-1)/2;
	aux[2]=(x*x+1)/2;

	if(aux[2]*aux[2]==aux[1]*aux[1]+aux[0]*aux[0])
	{
		printf("%lld %lld\n", aux[1], aux[2]);
		return;
	}

	ll aux2[3], y;
	y=aux2[0]=sqrt(8*(x+2))/2;
	aux2[1]=x;
	aux2[2]=(y*y+1)/2;

	if(aux2[2]*aux2[2]==aux2[1]*aux2[1]+aux2[0]*aux2[0])
	{
		printf("%lld %lld\n", aux2[0], aux2[2]);
		return;
	}

	ll aux3[3];
	y=aux3[0]=sqrt(8*(x-2))/2;
	aux3[1]=(y*y-1)/2;
	aux3[2]=x;

	if(aux3[2]*aux3[2]==aux3[1]*aux3[1]+aux3[0]*aux3[0])
	{
		printf("%lld %lld\n", aux3[0], aux3[1]);
		return;
	}

	queue<node>fila;
	fila.push( node(3, 4, 5) );
	while(!fila.empty() && data.size()<1000000)
	{
		ll a=fila.front().a;
		ll b=fila.front().b;
		ll c=fila.front().c;
		data.pb(node(a, b, c));
		fila.pop();
		ll na, nb, nc;
		na=-a+2*b+2*c;
		nb=-2*a+b+2*c;
		nc=-2*a+2*b+3*c;
		fila.push(node(na, nb, nc));

		na=a+2*b+2*c;
		nb=2*a+b+2*c;
		nc=2*a+2*b+3*c;
		fila.push(node(na, nb, nc));

		na=a-2*b+2*c;
		nb=2*a-b+2*c;
		nc=2*a-2*b+3*c;
		fila.push(node(na, nb, nc));
	}
	for(int i=0; i<data.size(); i++)
	{
		ll a=data[i].a;
		ll b=data[i].b;
		ll c=data[i].c;
		if(x%a==0)
		{
			ll q=x/a;
			printf("%lld %lld\n", q*b, q*c);
			return;
		}
		if(x%b==0)
		{
			ll q=x/b;
			printf("%lld %lld\n", q*a, q*c);
			return;
		}
		if(x%c==0)
		{
			ll q=x/c;
			printf("%lld %lld\n", q*a, q*b);
			return;
		}
	}
	printf("-1\n");
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
	ll x;
	scanf("%lld", &x);
  double t = clock();
	solve(x);
  printf("Done in %.6lf\n",(clock()-t)/CLOCKS_PER_SEC);
	return 0;
}