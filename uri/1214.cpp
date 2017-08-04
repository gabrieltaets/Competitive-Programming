#include <bits/stdc++.h>
using namespace std;
int main(){
  int c;
  scanf("%d",&c);
  while(c--){
    int n;
    scanf("%d",&n);
    int notas[n];
    double media = 0;
    for(int i = 0; i < n; i++){
      scanf("%d",&notas[i]);
      media += notas[i];
    }
    media /= (double)n;
    //printf("media = %.3f\n",media);
    int cont = 0;
    for(int i = 0; i < n; i++){
      if(notas[i] > media) cont++;
    }
    media = (double)100.0*cont/n;
    printf("%.3lf%%\n",media);
  }
  return 0;
}