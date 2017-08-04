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

int graph[40][40], p[40];
int s = 0, t = 38, total, f, mf;
set<int> used;
void showgraph();

void init(){
  used.clear();
  used.insert(0);
  used.insert(38);
  total = mf = 0;
  memset(graph,0,sizeof graph);
  for(int i = '0'; i <= '9'; i++){
    graph[i-'0'+27][38] = 1;
  }
}

void augment(int v, int minEdge){
  if(v == s){
    f = minEdge; return;
  }
  if(p[v] == -1) return;
  augment(p[v], min(minEdge,graph[p[v]][v]));
  graph[p[v]][v] -= f;
  graph[v][p[v]] += f;
}

void bfs(){
  while(1){
    //getchar();
    //showgraph();
    f = 0;
    bool vis[40];
    memset(vis,0,sizeof vis);
    memset(p,-1,sizeof p);
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int v = 0; v < 40; v++){
        if(graph[u][v] && !vis[v]){
          q.push(v);
          vis[v] = true;
          p[v] = u;
        }
      }
    }
    augment(t,INF);
    if(!f) break;
    mf += f;
  }
}

void showgraph(){
  printf("RESIDUAL\n");
  printf("  S ");
  for(int i = 'A'; i <= 'Z'; i++){
    if(!used.count(i-'A'+1)) continue;
    printf("%c ",i);
  }
  for(int i = '0'; i <= '9'; i++){
    if(!used.count(i-'0'+27)) continue;
    printf("%c ",i);
  }
  printf("T\n");
  
  for(int i = 0; i <= 38; i++){
    if(!used.count(i)) continue;
    if(!i) printf("S ");
    if(i && i <= 26) printf("%c ",'A'+i-1);
    if(i >= 27 && i < 38) printf("%c ",'0'+i-27);
    if(i == 38) printf("T ");
    for(int j = 0; j <= 38; j++){
      if(!used.count(j)) continue;
      if(graph[i][j] == INF) printf("I ");
      else printf("%d ",graph[i][j]);
    }
    printf("\n");
  }
}

int main(){
  char line[30];
  init();
  while(gets(line)){
    if(!strlen(line)){
      bfs();
      if(mf != total){
        printf("!");
      }
      else {
        for(int i = '0'; i <= '9'; i++){
          int j;
          for(j = 'A'; j <= 'Z'; j++){
            if(graph[i-'0'+27][j-'A'+1]){
              putchar(j);
              break;
            }
          }
          if(j == 'Z'+1) putchar('_');
        }
      }
      printf("\n");
      init();
      continue;
    }
    char job = line[0];
    used.insert(job-'A'+1);
    
    int qtd = line[1]-'0';
    total += qtd;
    graph[0][job-'A'+1] = qtd;
    for(int i = 3; line[i] != ';'; i++){
      graph[job-'A'+1][line[i]-'0'+27] = 1;
      used.insert(line[i]-'0'+27);
    }
    //showgraph();
  }
  bfs();
  if(mf != total){
    printf("!");
  }
  else {
    for(int i = '0'; i <= '9'; i++){
      int j;
      for(j = 'A'; j <= 'Z'; j++){
        if(graph[i-'0'+27][j-'A'+1]){
          putchar(j);
          break;
        }
      }
      if(j == 'Z'+1) putchar('_');
    }
  }
  printf("\n");
  return 0;
}
