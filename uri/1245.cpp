#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  while(scanf("%d",&N)!=EOF && N){
    int e[100], d[100];
    memset(e,0,sizeof e);
    memset(d,0,sizeof d);
    for(int i = 0; i < N; i++){
      int x;
      char p;
      scanf("%d %c",&x,&p);
      if(p == 'D') d[x]++;
      else e[x]++;
    }
    int cont = 0;
    for(int i = 30; i <= 60; i++){
      cont += min(e[i],d[i]);
    }
    cout << cont << endl;
  }
  return 0;
}