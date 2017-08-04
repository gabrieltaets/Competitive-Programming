#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int N, E;
int graph[510][510];
vii adjList[510];

int dijkstra(int s, int d){
  //printf("Source: %d  Sink: %d\n",s,d);
  int dist[510];
  memset(dist,INF,sizeof dist);
  priority_queue<ii,vii,greater<ii> > pq;
  pq.push(mp(0,s));
  dist[s] = 0;
  while(!pq.empty()){
    int u = pq.top().S, distance = pq.top().F;
    pq.pop();
    if(dist[u] < distance) continue;
    //printf("At vertex %d, dist = %d\n",u,distance);
    for(int i = 0; i < adjList[u].size(); i++){
      int v = adjList[u][i].F, w = adjList[u][i].S;
      //printf("Checking vertex %d, edge weight %d\n",v,w);
      if(distance+w < dist[v]){
        dist[v] = distance + w;
        //printf("Pushed %d with distance %d\n",v,dist[v]);
        pq.push(mp(dist[v],v));
      }
    }
  }
  return dist[d];
}

int main(){
  while(scanf("%d %d",&N,&E)!=EOF && N){
    memset(graph,INF,sizeof graph);
    for(int i = 0; i <= 500; i++) {
      graph[i][i] = 0;
      adjList[i].clear();
    }
    for(int i = 0; i < E; i++){
      int x, y, w;
      scanf("%d %d %d",&x,&y,&w);
      graph[x][y] = w;
      if(graph[y][x] != INF) graph[x][y] = graph[y][x] = 0;
    }
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if(i == j) continue;
        if(graph[i][j] != INF) {
         // printf("Set edge %d->%d weighing %d\n",i,j,graph[i][j]);
          adjList[i].pb(mp(j,graph[i][j]));
        }
      }
    }
    int Q;
    scanf("%d",&Q);
    while(Q--){
      int x, y;
      scanf("%d %d",&x,&y);
      int d = dijkstra(x,y);
      if(d == INF) printf("Nao e possivel entregar a carta\n");
      else printf("%d\n",d);
    }
    printf("\n");
  }
  return 0;
}
