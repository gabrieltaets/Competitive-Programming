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

bool test(ll n){
  ll ma = n*n*n;
}

int main(){
  ll m;
  cin >> m;
  ll lo = 1LL, hi = 100000LL, mid, ans = -1LL;
  while(lo <= hi){
    mid = (lo+hi)/2LL;
    if(test(mid) == m) {
      ans = mid;
      hi = mid-1LL;
    }
    else lo = mid+1LL;
  }
  cout << ans << endl;
  return 0;
}
