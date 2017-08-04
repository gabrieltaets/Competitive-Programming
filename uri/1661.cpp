#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll a[100100];
int main(){
  int n;
  while(scanf("%d",&n)!=EOF && n){
    ll s = 0;
    for(int i = 0; i < n; i++){
      scanf("%lld",&a[i]);
      if(!i) continue;
      if(a[i-1] < 0) s -= a[i-1];
      else s += a[i-1];
      a[i] += a[i-1];
    }
    cout << s << endl;
  }
  return 0;
}
