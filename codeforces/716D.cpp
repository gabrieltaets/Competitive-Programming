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

vii graph[1010];
int n, e, L, s, t;
ii dist[1010];
struct Q{
  int node, distance, erased;
  Q(){}
  Q(int x, int y, int z){
    node = x;
    distance = y;
    erased = z;
  }
  bool operator<(const Q &x) const {
    return distance < x.distance;
  }
  bool operator>(const Q &x) const {
    return x.distance < distance;
  }
};

int pai[1010][1010];
set<pair<pair<int,int>,int> > edges;

bool dif(int x, int y){
  for(int i = 0; i <= n; i++){
    if(pai[x][i] != pai[y][i]) {
      //printf("Pai[%d][%d]=%d, Pai[%d][%d]=%d\n",x,i,pai[x][i],y,i,pai[y][i]);
      return true;
    }
  }
  return false;
}

bool dijkstra(int pos){
  //getchar();
  for(int i = 0; i <= 1000; i++) pai[pos][i] = -1;
  for(int i = 0; i <= n; i++) dist[i] = ii(INF,0);
  dist[s] = ii(0,0);
  priority_queue<Q,vector<Q>,greater<Q> > pq;
  pq.push(Q(s,0,0));
  while(!pq.empty()){
    int a = pq.top().node, distance = pq.top().distance, erased = pq.top().erased;
    pq.pop();
    if(dist[a].F < distance) continue;
    for(int i = 0; i < graph[a].size(); i++){
      int g = graph[a][i].F;
      if(dist[g].F > distance + graph[a][i].S){
        if(!graph[a][i].S){
          pq.push(Q(g,distance,erased+1));
          dist[g] = ii(distance,erased+1);
        }
        else {
          pq.push(Q(g,distance+graph[a][i].S,erased));
          dist[g] = ii(distance+graph[a][i].S,erased);
        }
        //printf("set pai[%d][%d]=%d\n",pos,g,a);
        pai[pos][g] = a;
      }
    }
  }
  //printf("Dist[%d] = %d\n",t,dist[t]);
  if(dist[t].F > L) return false;
  if(dist[t].F == L && dist[t].S > 0 && pos==0) return false;
  if(dist[t].F < L && dist[t].S == 0) return false;
  if(dist[t].S > L) return false;
  int q0 = dist[t].S, qs = L-dist[t].F;
  for(int i = t; i != -1; i = pai[pos][i]){
    for(int j = 0; j < graph[i].size(); j++){
      if(graph[i][j].F == pai[pos][i]){
        if(graph[i][j].S == 0){
          graph[i][j].S = 1;
          q0--;
          if(q0 <= 0) graph[i][j].S = qs;
          for(int k = 0; k < graph[pai[pos][i]].size(); k++){
            if(graph[pai[pos][i]][k].F == i) graph[pai[pos][i]][k].S = graph[i][j].S;
          }
          qs--;
        }
      }
    }
  }
  return true;
}

int main(){
  cin >> n >> e >> L >> s >> t;
  for(int i = 0; i < e; i++){
    int u, v, w;
    scanf("%d %d %d",&u,&v,&w);
    graph[u].pb({v,w});
    graph[v].pb({u,w});
  }
  if(dijkstra(0)){
    //printf("OK\n");
    bool ans = true;
    for(int i = 1;; i++){
      //printf("Dijkstra %d\n",i);
      ans &= dijkstra(i);
      if(!dif(i,i-1)) break;  
    }
    if(!ans){
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
      for(int j = 0; j < graph[i].size(); j++){
        int u = min(i,graph[i][j].F);
        int v = max(i,graph[i][j].F);
        int w = graph[i][j].S;
        if(!w) w = INF;
        edges.insert({{u,v},w});
      }
    }
    for(set<pair<ii,int> >::iterator it = edges.begin(); it != edges.end(); it++){
      printf("%d %d %d\n",it->F.F,it->F.S,it->S);
    }
  }
  else cout << "NO\n";
  return 0;
}
