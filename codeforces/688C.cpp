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
int color[100010];
bool active[100010], flag;
vi graph[100010], A, B;
int n,m;
void bfs(int s){
  queue<int> q;
  q.push(s);
  int c = color[s] = 1;
  A.pb(s);
  while(!q.empty()){
    int x = q.front(); q.pop();
    c = (color[x] == 1 ? 2 : 1);
    for(int i = 0; i < graph[x].size(); i++){
      if(color[graph[x][i]] == 0){
        color[graph[x][i]] = c;
        q.push(graph[x][i]);
        if(c == 1) A.pb(graph[x][i]);
        else B.pb(graph[x][i]);
      }
      else if(color[graph[x][i]] != c) {
        //printf("%d = %d\n",x,graph[x][i]);
        flag = true;
        break;
      }
    }
  }
}
int solve(){
  memset(color,0,sizeof color);
  flag = false;
  for(int i = 0; i < n; i++){
    if(!color[i] && active[i]) bfs(i);
    if(flag) return -1;
  }
  return 1;  
}
int main(){
  cin >> n >> m;
  memset(active,false,sizeof active);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
    active[u] = active[v] = true;
  }
  if(solve() == -1) printf("-1\n");
  else {
    printf("%d\n",A.size());
    bool check = false;
    for(int i = 0; i < A.size(); i++){
      if(check) putchar(' ');
      printf("%d",A[i]);
      check = true;
    }
    printf("\n%d\n",B.size());
    check = false;
    for(int i = 0; i < B.size(); i++){
      if(check) putchar(' ');
      printf("%d",B[i]);
      check = true;
    }
  }
  return 0;
}
