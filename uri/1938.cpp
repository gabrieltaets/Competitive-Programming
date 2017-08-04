#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  scanf("%d",&N);
  pair<int,int> poste[N];
  for(int i =0; i < N; i++){
    scanf("%d %d",&poste[i].first,&poste[i].second);
  }
  sort(poste,poste+N);
  int sum = 0;
  for(int i = 0; i < N-1; i++){
    int lastup = (int)1e9, lastdown = -(int)1e9;
    for(int j = i+1; j < N; j++){
      if(poste[j].second > poste[i].second && poste[j].second < lastup){
        sum++;
        lastup = poste[j].second;
      }
      else if(poste[j].second < poste[i].second && poste[j].second > lastdown){
        sum++;
        lastdown = poste[j].second;
      }
    }
  }
  printf("%d\n",sum);
  return 0;
}