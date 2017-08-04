#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n, k;
int c[100010];
set<int> rm;
int main(){
  scanf("%d %d",&n,&k);
  ll ans = 0, sum = 0;
  for(int i = 1; i <= n; i++){
    scanf("%d",&c[i]);
    sum += c[i];
    if(i>1) ans += c[i]*c[i-1];
  }
  ans += c[n]*c[1];
  c[0] = c[n];
  c[n+1] = c[1];
  ll disc = 0;
  for(int i = 0; i < k; i++){
    int idx;
    scanf("%d",&idx);
    int l, r;
    l = (idx==1?n:idx-1);
    r = (idx==n?1:idx+1);
    bool flag1 = rm.insert(l).second;
    if(flag1) {
      disc += c[l];
      rm.erase(l);
    }
    bool flag2 = rm.insert(r).second;
    if(flag2) {
      disc += c[r];
      rm.erase(r);
    }
    rm.insert(idx);
    disc += c[idx];
    ans += (sum-disc)*c[idx];
    if(flag1) disc -= c[l];
    if(flag2) disc -= c[r];
  }
  cout << ans << endl;  
  return 0;
}
