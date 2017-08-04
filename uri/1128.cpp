#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> graph[2005], graphr[2005];
int bfs(int s, vector<int>(&g)[2005]){
  int vis[2005];
  memset(vis,0,sizeof vis);
  vis[s] = 1;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int a = q.front(); q.pop();
    for(int i = 0; i < g[a].size(); i++){
      if(!vis[g[a][i]]){
        q.push(g[a][i]);
        vis[g[a][i]] = 1;
      }
    }
  }
  for(int i = 1; i <= N; i++){
    if(!vis[i]) return 0;
  }
  return 1;
}
int main(){
  while(scanf("%d %d",&N,&M)!=EOF && (N+M)){
    int v, w, p;
    for(int i = 0; i <= N; i++){
      graph[i].clear();
      graphr[i].clear();
    }
    for(int i = 0; i < M; i++){
      scanf("%d %d %d",&v,&w,&p);
      graph[v].push_back(w);
      graphr[w].push_back(v);
      if(p==2) {
        graph[w].push_back(v);
        graphr[v].push_back(w);
      }
    }
    printf("%d\n",bfs(1,graph) && bfs(1,graphr));    
  }
  return 0;
}