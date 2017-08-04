#include <bits/stdc++.h>
using namespace std;
long long expmod(long long b, long long e){
  if(e == 0LL) return 1LL;
  long long ans = expmod(b,e/2)%1000000007LL;
  ans = (ans*ans)%1000000007LL;
  if(b&1LL) ans = (ans*(b%1000000007LL))%1000000007LL;
  return ans;
}
int main(){
  long long A, B, x, n;
  cin >> A >> B >> x >> n;
  cout << expmod(A,n-1) << endl;
  long long S = ((B*(expmod(A,n-1)-1))%1000000007LL)/(A-1);
  cout << S << endl;
  S += (expmod(A,n)*x)%1000000007LL;
  cout << S << endl;
  return 0;
}