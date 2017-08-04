#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int N, M, C, K;
vii graph[260];
int dist[260];
void dijkstra(int s){
  memset(dist,0x3f3f3f3f,sizeof dist);
  dist[s] = 0;
  priority_queue<iii, viii, greater <iii> > pq;
  pq.push(iii(0,ii(s,0)));
  while(!pq.empty()){
    iii front = pq.top(); pq.pop();
    int distancia = front.first;
    int vertice = front.second.first;
    int rota = front.second.second;
    if(distancia > dist[vertice]) continue;    
    for(int i = 0; i < graph[vertice].size(); i++){
      ii destino = graph[vertice][i];
      if(rota){
        if(destino.first == vertice+1 && distancia + destino.second < dist[destino.first]){
          dist[destino.first] = distancia + destino.second;
          pq.push(iii(dist[destino.first],ii(destino.first,1)));
        }
      }
      else if(distancia + destino.second < dist[destino.first]){
        dist[destino.first] = distancia + destino.second;
        pq.push(iii(dist[destino.first],ii(destino.first,destino.first<C?1:0)));
      }
    }
  }     
}

int main(){
  
  while(scanf("%d %d %d %d",&N,&M,&C,&K)!=EOF && (N+M+C+K)){
    for(int i = 0; i <= N; i++){
      graph[i].clear();
    }
    int u, v, p;
    for(int i = 0; i < M; i++){
      scanf("%d %d %d",&u,&v,&p);
      graph[u].push_back(make_pair(v,p));
      graph[v].push_back(make_pair(u,p));
    }
    dijkstra(K);
    printf("%d\n",dist[C-1]);
  }
  return 0;
}