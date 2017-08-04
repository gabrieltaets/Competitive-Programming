#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n, m;
vi graph[1010];
int vis[1010];

void dfs(int node){
  vis[node] = 1;
  int x;
  for(int i = 0; i < graph[node].size(); i++){
    x = graph[node][i];
    if(!vis[x]) dfs(x);
  }
}

string solve(){
  if(m != n-1) return string("no");
  memset(vis,0,sizeof vis);
  dfs(1);
  for(int i = 1; i <= n; i++){
    if(!vis[i]) return string("no");
  }
  return string("yes");
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  cout << solve() << endl;  
  return 0;
}
