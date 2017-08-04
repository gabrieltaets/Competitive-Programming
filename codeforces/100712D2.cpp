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
#define lcm(x,y) (x*y)/gcd(x,y)
#define bitcount(x) __builtin_popcount(x)
#define llbitcount(x) __builtin_popcountll(x)
 
enum {North, East, South, West};
//{0, 1, 2, 3}
//{Up, Right, Down, Left}
 
int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
const int MN=1005;
 
int k;
string str;
bool memo[MN];
int dp[MN];
 
bool f(string x)
{
    if(x.size()==1)
        return true;
 
    int v=x[0]-'0';
    for(int i=1; i<x.size(); i++)
    {
        if((x[i]-'0')==v)
            return true;
        v^=1;
    }
    return false;
}
 
int solve(int i)
{
    if(i==str.size())
        return 0;
    if(memo[i])
        return dp[i];
    int &ret=dp[i]=INF;
    for(int j=i; j<str.size(); j++)
    {
        if(abs(i-j)>k)
            break;
        if(f(str.substr(i, (int)(abs(i-j)+1))));
            ret=min(ret, 1+solve(j+1));
    }
    memo[i]=true;
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
    int tt;
    scanf("%d", &tt);
    while(tt--)
    {
        int n;
        scanf("%d %d", &n, &k);
        cin >> str;
 
        RESET(memo, false);
        printf("%d\n", solve(0));
    }
    return 0;
}