#include <bits/stdc++.h>
using namespace std;
int N;
long long A[110];
long long solve(int n, int v){
  long long x = 0;
  for(int i = 0; i < N; i++){
    if(i == n) x ^= A[i]/v;
    else x ^= A[i];
  }
  return x;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    long long x = 0;
    for(int i = 0; i < N; i++){
      scanf("%lld",&A[i]);
    }
    for(int i = 0; i < N; i++){
      x ^= A[i];
    }
    bool flag = false;
    if(!x) printf("Henry\n");
    else {
      for(int i = 0; i < N; i++){
        for(int j = 2; j <= 6; j++){
          x = solve(i,j);
          if(!x){
            flag = true;
            break;
          }
        }
        if(flag) break;
      }
      if(flag) printf("Derek\n");
      else printf("Henry\n");
    }
  }
  return 0;
}