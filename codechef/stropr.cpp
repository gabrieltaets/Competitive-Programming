#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
  int T;
  scanf("%d",&T);
  long long v[100010];
  v[0] = 0;
  while(T--){
    int N, x;
    long long M, A;
    scanf("%d %d %lld",&N,&x,&M);
    for(int i = 1; i <= N; i++){
      scanf("%lld",&v[i]);
    }
    
    for(int i = x - 1; i > 0; i--){
      v[x] = v[x] + ((((v[i]%MOD)*(M%MOD))%MOD)*(x-i))%MOD;
    }
    printf("%lld\n",v[x]);
  }
  return 0;
}