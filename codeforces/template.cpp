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
int N, S, F, E;
vii graph[100];
int pai[100];

int dijkstra(){
  priority_queue<ii,vii,greater<ii> > pq;
  int dist[100];
  for(int i = 0; i <= N; i++) {
    dist[i] = INF;
    pai[i] = -1;
  }
  dist[S] = 0;
  pq.push(mp(0,S));
  while(!pq.empty()){
    int v = pq.top().S, distance = pq.top().F;
    pq.pop();
    if(distance > dist[v]) continue;
    for(int i = 0; i < graph[v].size(); i++){
      int u = graph[v][i].F, w = graph[v][i].S;
      if(dist[u] > distance+w){
        dist[u] = distance+w;
        pai[u] = v;
        pq.push(mp(dist[u],u));
      }
    }
  }
  return dist[F];
}

int main(){
  while(scanf("%d",&N)!=EOF && N){
    scanf("%d %d",&S,&F);
    scanf("%d",&E);
    for(int i = 0; i < E; i++){
      int a, b, d;
      scanf("%d %d %d",&a,&b,&d);
      graph[a].pb(mp(b,d));
      graph[b].pb(mp(a,d));
    }
    printf("%d\n",dijkstra());
    stack<int> st;
    for(int i = F; pai[i] != -1; i = pai[i]){
      st.push(i);
    }
    printf("%d",S);
    while(!st.empty()){
      printf(" %d",st.top());
      st.pop();
    }
    putchar('\n');
  }
  return 0;
}
