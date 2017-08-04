#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  long long r[55];
  cin >> k;
  r[0] = 1LL; r[1] = 2LL;
  for(int i = 2; i <= 50; i++){
    r[i] = r[i-1] + r[i-2];
  }
  for(int c = 1; c <= k; c++){
    cin >> n;
    printf("Scenario #%d:\n%lld\n\n",c,r[n]);
  }
  return 0;
}