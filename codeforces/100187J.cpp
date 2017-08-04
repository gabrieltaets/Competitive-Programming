#include <bits/stdc++.h>
using namespace std;
int N, K;
int cards[200010];
vector<int> aresta[200010];
int vis[200010];
void dfs(int no){
  if(vis[no]) return;
  vis[no] = 1;
  for(int i = 0; i < aresta[no].size(); i++){
    dfs(aresta[no][i]);
  }
}
int main(){
  scanf("%d",&N);
  for(int i = 0; i <= N; i++) vis[i] = 0;
  int x;
  for(int i = 1; i <= N; i++){
    scanf("%d",&x);
    cards[x]=i;
  }
  scanf("%d",&K);
  for(int i = 1; i <= K; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d",&x);
      aresta[x].push_back(j);
    }
  }
  scanf("%d",&x);
  dfs(cards[x]);
  if(vis[x]) printf("YES\n");
  else printf("NO\n");
  return 0;
}