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
int b, n, fim;
map<string,int> comp;
vii edge[1100];

int bfs(){
  queue<pair<int,ii> > q;
  q.push(mp(0,edge[0][0]));
  int maxflow = 0;
  ii d[1100];
  for(int i = 1; i <= n; i++){
    d[i] = ii(0,INF);
  }
  while(!q.empty()){
    int vertex = q.front().F;
    int flow = q.front().S.F;
    int cost = q.front().S.S;
    q.pop();
    if(vertex == fim){
      if(flow > maxflow && cost <= b) maxflow = flow;
    }
    if(d[vertex].F > flow && d[vertex].S < cost) continue;
    for(int i = 0; i < edge[vertex].size(); i++){
      q.push(mp(vertex+1,mp(min(flow,edge[vertex][i].F),cost+edge[vertex][i].S)));
    }
  }
  return maxflow;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&n,&b);
    int cont = 1;
    edge[0].pb(mp(b,0));
    for(int i = 0; i < n; i++){
      string type, name;
      int price, quality;
      cin >> type >> name >> price >> quality;
      if(comp.insert(mp(type,cont)).second){
        cont++;
      }
      int v = comp[type];
      edge[v].pb(mp(quality,price));
    }
    fim = cont;
    printf("%d\n",bfs());
  }
  return 0;
}