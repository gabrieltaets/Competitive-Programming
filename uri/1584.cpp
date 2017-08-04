#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e){
  if(!e) return 1;
  long long ans = power(b,e/2)%1000000007;
  ans = (ans*ans)%1000000007;
  if(e&1) ans = (ans*b)%1000000007;
  return ans;
}
int main(){
  long long N, K;
  while(scanf("%lld %lld",&N,&K)!=EOF){
    long long each;
    switch(N){
     case 2:
      each = 2 + (N-1)*(N-1);
      break;
     case 3:
      
      
    }
    each = N*N*power(each,K);
    cout << each%1000000007 << endl;
  }
  return 0;
}