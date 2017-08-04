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
 
void init()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cout << "[FREOPEN]" << endl;
    return;
}
 
int main()
{
    int n;
    scanf("%d", &n);
    vector<int>datap,datan;
    for(int i=0; i<n; i++)
    {
        int s, a;
        cin >> s >> a;
        if(s>0)
          datap.pb(-a);
        else
          datan.pb(-a);
    }
    cout << endl;
    sort(datap.begin(), datap.end());
    sort(datan.begin(), datan.end());
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int x;
        cin >> x;
        int ans = 0;
        ans += datap.end() - lower_bound(datap.begin(), datap.end(), -x);
        ans += datan.end() - lower_bound(datan.begin(), datan.end(), x);
        cout << ans << endl;
    }
    return 0;
}