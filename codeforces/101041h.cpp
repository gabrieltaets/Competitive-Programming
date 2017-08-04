#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define MAXN 250
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi graph[MAXN];
vii EdgeList;
int n, m, vis[MAXN];

void dfs(int u, ii edge){
  vis[u] = 1;
  for(int i = 0; i < graph[u].size(); i++){
    int x = graph[u][i];
    if(edge == ii(u,x)) continue;
    if(!vis[x]) dfs(x,edge);
  }
}

int main(){
  cin >> n >> m;
  int u, v;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    graph[u].pb(v);
    EdgeList.pb(ii(u,v));
  }
  cin >> u >> v;
  for(int i = 0; i < EdgeList.size(); i++){
    memset(vis,0,sizeof vis);
    dfs(u,EdgeList[i]);
    if(!vis[v]){
      printf("1\n");
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
