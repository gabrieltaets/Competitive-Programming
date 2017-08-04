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
vi graph[200005];

vi dist(200005,INF); 
int V; 

void bfs(){
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while(!q.empty()){
    int a = q.front(); q.pop();
    for(int i = 0; i < graph[a].size(); i++){
      if(dist[graph[a][i]] == INF) {
        q.push(graph[a][i]);
        dist[graph[a][i]] = dist[a]+1;
      }
    }
  }
}


int main(){
  scanf("%d",&V);
  for(int i = 1; i <= V; i++){
    graph[i].pb(i+1);
    graph[i].pb(i-1);
    int s;
    scanf("%d",&s);
    graph[i].pb(s);
  }
  bfs();
  printf("0");
  for(int i = 2; i <= V; i++){
    printf(" %d",dist[i]);
  }
  return 0;
}
