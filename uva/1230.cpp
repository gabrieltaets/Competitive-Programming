#include <bits/stdc++.h>
using namespace std;

long long fastExp(int b, int p, int MOD){
  if(p == 0) return 1;
  if(p == 1 || b == 1) return b;
  long long res = fastExp(b, p/2,MOD)%MOD;
  res *= res;
  res %= MOD;
  if(p%2 == 1) res *= b%MOD;
  return res%MOD;  
}

int main(){
  int c, x, y, n;
  cin >> c;
  while(c--){
    scanf("%d %d %d",&x,&y,&n);
    printf("%lld\n",fastExp(x,y,n));
  }
  cin >> c;
  return 0;
}