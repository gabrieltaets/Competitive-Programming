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
 
int n;
int q[200], ans[200];
map< pair<int, vector<int> >, int>dp;
 
int solve(int i, vector<int>v)
{
    if(i==n)
        return 0;
    if(dp.count(mp(i,v)))
        return dp[mp(i,v)];
    int ret=INF;
    ret=min(ret, abs(q[i]-1)+solve(i+1, v));
    for(int j=0; j<v.size(); j++)
    {
        int x=v[j];
        vector<int>aux;
        for(int k=0; k<v.size(); k++)
            if(v[k]%x!=0)
                aux.pb(v[k]);
        ret=min(ret, abs(q[i]-x)+solve(i+1, aux));
    }
    return dp[mp(i, v)]=ret;
}
 
void trace(int i, vector<int>v)
{
    if(i==n)
        return;
    int mx=INF, px=1;
    vector<int>v2;
    if(abs(q[i]-1)+solve(i+1, v)<mx)
    {
        mx=abs(q[i]-1)+solve(i+1, v);
        v2=v;
        px=1;
    }
    for(int j=0; j<v.size(); j++)
    {
        int x=v[j];
        vector<int>aux;
        for(int k=0; k<v.size(); k++)
            if(v[k]%x!=0)
                aux.pb(v[k]);
        if(abs(q[i]-x)+solve(i+1, aux)<mx)
        {
            mx=abs(q[i]-x)+solve(i+1, aux);
            px=x;
            v2=aux;
        }
    }
    ans[i]=px;
    trace(i+1, v2);
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
    vector<int>aux;
    for(int i=2; i<=30; i++)
        aux.pb(i);
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &q[i]);
    solve(0, aux);
    trace(0, aux);
    for(int i=0; i<n; i++)
    {
        i>0?printf(" "):printf("");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}