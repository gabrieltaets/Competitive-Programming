#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, c = 0;
  while(scanf("%d",&n) && n){
    if(c) printf("\n");
    int freq[250];
    memset(freq,0,sizeof freq);
    int a, b;
    double nump = 0, con = 0;
    for(int i = 0; i < n; i++){
      scanf("%d %d",&a,&b);
      freq[b/a] += a;
      nump += a;
      con += b;
    }
    printf("Cidade# %d:\n",++c);
    bool flag = false;
    for(int i = 0; i <= 200; i++){
      if(freq[i]){
        if(flag) putchar(' ');
        printf("%d-%d",freq[i],i);
        flag = true;
      }
    }
    int m = 100*(con/nump);
    printf("\nConsumo medio: %.2f m3.\n",m/100.0);
  }
  return 0;
}