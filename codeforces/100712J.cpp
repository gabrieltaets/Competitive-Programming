#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N, M, x;
    scanf("%d %d",&N,&M);
    int aluno[20], pacote[60];
    memset(aluno,0,sizeof aluno);
    memset(pacote,0,sizeof pacote);
    for(int i = 0; i < N; i++){
      scanf("%d",&x);
      aluno[x]++;
    }
    for(int i = 0; i < M; i++){
      scanf("%d",&x);
      pacote[x]++;
    }
    vector<int> a, p;
    for(int i = 5; i <= 15; i++){
      if(aluno[i]) a.push_back(aluno[i]);
    }
    for(int i = 1; i <= 50; i++){
      if(pacote[i]) p.push_back(pacote[i]);
    }
    if(a.size() > p.size()){
      printf("NO\n");
      continue;
    }
    int cont = 0, j = 0;
    //printf("a = %d\np = %d\n",a.size(),p.size());
    for(int i = 0; i < a.size(); i++){
      for(; j < p.size(); j++){
        if(a[i] <= p[j]){
          cont++;
          j++;
          break;
        }
      }
    }
    if(cont == a.size()) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}