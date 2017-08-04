#include <bits/stdc++.h>
using namespace std;
int main(){
  int p, a, b, c, d, n;
  while(scanf("%d %d %d %d %d %d",&p,&a,&b,&c,&d,&n)!=EOF){
    double maxq = 0, pmax = 0, preco, pmin = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
      preco = p*(sin(a*i+b)+cos(c*i+d)+2);
      if(maxq < pmax - preco){
        pmin = preco;
        maxq = pmax - preco;
      }
      if(preco > pmax) pmax = preco;
      if(preco < pmin) pmin = preco;
    }
    printf("%lf\n",maxq);
  }
  return 0;
}