#include <bits/stdc++.h>
using namespace std;
inline int mdc(int a, int b){
  return b ? mdc(b,a%b) : abs(a);
}
int main(){
  int n, m, g;
  cin >> n >> m;
  n--; m--;
  if(n < m) swap(n,m);
  g = mdc(n,m);
  n /= g; m /= g;  
  if(n % m == 0) printf("%d",n*g);
  else {
    printf("%d\n",g*(n+m-1));
  }
  return 0;
}