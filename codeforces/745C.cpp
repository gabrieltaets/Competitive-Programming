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

int n, m, k;
vi gov;
vi graph[1035];
int vis[100035];
int cont[1035];

void dfs(int node, int p, int g){
  cont[g]++;
  vis[node] = 1;
  for(int i = 0; i < graph[node].size(); i++){
    int to = graph[node][i];
    if(to == p) continue;
    if(!vis[to]) dfs(to,node,g);
  }
}

ll solve(){
  memset(vis,0,sizeof vis);
  memset(cont,0,sizeof cont);
  ii bg(-1,-1);
  for(int i = 0; i < gov.size(); i++){
    dfs(gov[i],-1,gov[i]);
    if(cont[gov[i]] > bg.S){
      bg = {gov[i],cont[gov[i]]};
    }
  }
  for(int i = 0; i < n; i++){
    if(!vis[i]) cont[bg.F]++;
  }
  ll total = 0;
  for(int i = 0; i < gov.size(); i++){
    total += cont[gov[i]]*(cont[gov[i]]-1)/2;
  }
  return total - m;
}

int main(){
  scanf("%d %d %d",&n,&m,&k);
  for(int i = 0; i < k; i++){
    int x;
    scanf("%d",&x);
    x--;
    gov.pb(x);
  }
  for(int i = 0; i < m; i++){
    int u, v;
    scanf("%d %d",&u,&v);
    u--; v--;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  cout << solve() << endl;
	return 0;
}
