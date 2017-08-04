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

int main(){
  ll l1, r1, l2, r2, k;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  ll lo, hi, ans;
  lo = max(l1, l2);
  hi = min(r1, r2);
  ans = hi-lo+1;
  if(k >= lo && k <= hi) ans--;
  cout << max(0LL,ans) << endl;
  return 0;
}
