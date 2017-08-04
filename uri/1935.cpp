#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
int main(){
  ll n, b;
  cin >> n >> b;
  ll l = 0, r = n/2, ans=0, sum, sum2;
  while(l <= r){
    ll mid = (l+r)/2;
    sum = mid*(4LL*(n-1LL)+(4LL*(n-1LL)-8LL*(mid-1LL)))/2LL;
    if(sum == b){
      ans = mid;
      sum2 = sum;
      break;
    }
    if(sum < b){
      l = mid+1;
      ans = mid;
      sum2 = sum;
    }
    else {
      r = mid-1LL;
    }
  }
  b -= sum2;
  ii pos(ans,ans);
  if(b) {
    if(b < n - 2LL*ans){
      pos.S += b;
    }
    else {
      pos.S += n - 2LL*ans;
      b -= n - 2LL*ans;
      if(b){
        if(b < n - 2LL*ans - 1LL){
          pos.F += b;
        }
        else {
          pos.F += n - 2LL*ans - 1LL;
          b -= n - 2LL*ans - 1LL;
          if(b){
            if(b < n - 2LL*ans - 1LL){
              pos.S -= b;
            }
            else {
              pos.S -= n - 2LL*ans - 1LL;
              b -= n - 2LL*ans - 1LL;
              if(b) pos.F -= b;
            }
          }
        }
      }
    }
  }
  cout << pos.F+1LL << " " << pos.S << endl;
  return 0;
}