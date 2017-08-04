#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(scanf("%d",&n) && n){
    char x;
    char in[30];
    char q[30];
    char s[30];
    int topopilha = 0, topofila = 0;
    for(int i = 0; i < n; i++) scanf(" %c",&in[i]);
    for(int i = 0; i < n; i++) {
      scanf(" %c",&x);
      q[i] = x;
    }
    for(int i = 0; i < n; i++){
      s[topopilha++] = in[i];
      //printf("PILHA = %s\nFILA = %s\n",s,q+topofila);
      printf("I");
      while(topopilha > 0 && topofila <= n && s[topopilha-1] == q[topofila]){
        topopilha--;
        topofila++;
        printf("R");
      }
    }
    //printf("Topopilha = %d topofila = %d\n",topopilha,topofila);
    if(topopilha > 0 || topofila < n) printf(" Impossible\n");
    else putchar('\n');
  }
  return 0;
}