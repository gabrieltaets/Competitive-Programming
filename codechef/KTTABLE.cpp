#include <bits/stdc++.h>
using namespace std;
int main(){
  int T, N;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    int A[N+1], B[N+1];
    A[0] = B[0] = 0;
    for(int i = 1; i <= N; i++){
      scanf("%d",&A[i]);
    }
    for(int i = 1; i <= N; i++){
      scanf("%d",&B[i]);
    }
    int cont = 0;
    for(int i = 1; i <= N; i++){
      if(A[i-1] + B[i] <= A[i]) cont++;
    }
    printf("%d\n",cont);
  }
  return 0;
}