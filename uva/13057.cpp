#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define MAXN 10010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector <int> g[MAXN];
int component[MAXN];
int scc;
vector <int> S;
bool in_stack[MAXN];
int indices[MAXN], lowlinks[MAXN], indice;
int vis[10010], removed[10010], visc[10010];
vi started;
int cur, cont;

void check(int node){
  int cn = component[node];
  for(int i = 0; i < g[node].size(); i++){
    int x = g[node][i];
    if(component[x] != cn && !removed[component[x]]){
      removed[component[x]]=1;
      cont--;
    }
  }
}

int solve(int m){
  cont = scc;
  memset(removed,0,sizeof removed);
  for(int i = 0; i < m; i++){
    check(i);
  }
  return cont;
}


void tarjan (int v) {
  indices[v] = indice;
  lowlinks[v] = indice;
  ++indice;
  S.push_back(v);
  in_stack[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
   int w = g[v][i];
   if (indices[w] == -1) {
     tarjan(w);
     lowlinks[v] = min (lowlinks[v], lowlinks[w]);
   }
   else if (in_stack[w])
    lowlinks[v]=min(lowlinks[v], indices[w]);
  }
  if (lowlinks[v] == indices[v]) {
   int w = S[S.size() - 1];
   S.pop_back();
   while (w != v) {
     in_stack[w] = false;
     component[w] = scc;
     w = S[S.size() - 1];
     S.pop_back();
   }
   component[v] = scc++;
   in_stack[v] = false;
  }
}

void scc_decomposition (int n) {
 for (int i = 0; i < n; ++i) {
   indices[i] = lowlinks[i] = component[i] = -1;
   in_stack[i] = 0;
 }
 S.clear();
 indice = scc = 0;
 for (int i = 0; i < n; ++i)
  if (component[i] == -1)
    tarjan(i);
}

int main(){
  int t;
  cin >> t;
  for(int c = 1; c <= t; c++){
    int n, m;
    scanf("%d %d",&m,&n);
    for(int i = 0; i <= m; i++) g[i].clear();
    for(int i = 0; i < n; i++){
      int a, b;
      scanf("%d %d",&a,&b);
      a--; b--;
      g[a].pb(b);
    }
    scc_decomposition(m);
    printf("Case %d: %d\n",c,solve(m));
  }
  return 0;
}
