#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N, S, coin[10];
    scanf("%d %d",&N,&S);
    for(int i = 0; i < N; i++) scanf("%d",&coin[i]);
    sort(coin,coin+N);
    int maxcoin = 0;
    for(int i = 0; i < (1<<N); i++){
      int cont = 0, sum = 0;
      for(int j = N-1; j >= 0; j--){
        if(i&(1<<j)) {
          cont++;
          if(sum >= S){
            cont = -1;
            break;
          }
          sum += coin[j];
        }
      }
      if(sum >= S){
        maxcoin = max(maxcoin,cont);
        /*if(cont != -1){
          printf("Valid: ");
          for(int j = N-1; j >= 0; j--){
            if(i&(1<<j)) printf("%d ",coin[j]);
          }
          printf("\n");
        }*/
      }
    }
    cout << maxcoin << endl;
  }
  return 0;
}