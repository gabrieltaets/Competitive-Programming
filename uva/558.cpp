#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 2010
using namespace std;

vector < pair <int,int> > edges; 
int graph[MAXN][MAXN], dist[MAXN], n, m;
bool bellman_ford(int s){   
  int qtdArestas = edges.size();   
  for(int i = 0; i < n; i++) dist[i] = INF; 
  dist[s] = 0; 
  for(int i = 0; i < n - 1; i++){     
    for(int j = 0; j < qtdArestas; j++){       
      int u = edges[j].first, v = edges[j].second;     
      if(dist[u] < INF && dist[v] > dist[u] + graph[u][v])       
        dist[v] = dist[u] + graph[u][v]; 
  } } 
  for(int i = 0; i < qtdArestas; i++){   
    int u = edges[i].first, v = edges[i].second;   
    if(dist[u] < INF && dist[v] > dist[u] + graph[u][v])   
      return false; 
  } 
  return true; 
} 

int main(){
  int c;
  cin >> c;
  while(c--){
    edges.clear();
    cin >> n >> m;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) graph[i][j] = 0;
    int x, y, z;
    for(int i = 0; i < m; i++){
      cin >> x >> y >> z;
      edges.push_back(make_pair(x, y));
      graph[x][y] = z;
    }
    if(bellman_ford(0)) printf("not possible\n");
    else printf("possible\n");
  }
  return 0;
}