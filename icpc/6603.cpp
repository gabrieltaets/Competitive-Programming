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

int n, m, cont, grau3;
vi graph[510], cycle;
int vis[510], subsize[510];
bool instack[510];
vii ans;

int dfs(int node, int pai, int depth){
  if(vis[node] != -1) return subsize[node];
  vis[node] = depth;
  instack[node] = true;
  cont++;
  if(graph[node].size() == 3) {
   // printf("%d has 3 sons\n",node);
    grau3++;
   // printf("grau3 = %d\n",grau3);
  }
  for(int i = 0; i < graph[node].size(); i++){
    int x = graph[node][i];
    if(x == pai) continue;
    if(instack[x]){
      cycle.pb(vis[node]-vis[x]+1);
    }
    else {
      int w = dfs(x,node,depth+1);
    //  printf("subsize[%d] += %d\n",node,w);
      subsize[node] += w;
    }
  }
  instack[node] = false;
  //printf("subsize[%d] = %d\n",node,subsize[node]);
  return subsize[node];
}

void solve(){
  ans.clear();
  cont = 0;
  memset(instack,0,sizeof instack);
  for(int i = 0; i <= n; i++) {
    subsize[i] = 1;
    vis[i] = -1;
  }
  ii root(-1,-1);
  for(int i = 1; i <= n; i++){
    root = max(root,ii(graph[i].size(),i));
  }
  
  int i = root.S, grade = root.F;
  if(grade > 3) return;
  
  //printf("DFS for %d\n",i);
  cont = grau3 = 0;
  cycle.clear();
  dfs(i,-1,0);
  for(int i = 1; i <= n; i++) if(vis[i] == -1) return;
  //printf("Found %d cycles, %d vertices (%d grade 3)\n",cycle.size(),cont,grau3);
  
  if(cycle.size() == 2 && grau3 == 2){ // 8
    //printf("HERE\n");
    //printf("cycle[0] = %d, cycle[1] = %d\n",cycle[0],cycle[1]);
    if(cycle[0] % 4 == 0 && cycle[1] % 4 == 0 && (cycle[0] == cycle[1] || cycle[0] == 3*cycle[1]/2 || cycle[1] == 3*cycle[0]/2)){
      int k = (cont - 6)/7;
      //printf("k = %d\n",k);
      //if(cont == cycle[0]+cycle[1]-k || cont == cycle[0]+3*cycle[1]/2-k || cont == cycle[1]+3*cycle[0]/2-k){
       // printf("Found 8 starting at %d\n",i);
        ans.pb(mp(8,k));
      //}
    }
  }
  if(cycle.size() == 1 && grau3 == 1){ // 6 ou 9
    //printf("Looking for 6, 9 or 0 at %d\n",i);
    if(cycle[0] % 4 == 0 && cont % 6 == 0) {
      //printf("Found 6 or 9 starting at %d\n",i);
      ans.pb(mp(6,(cont-6)/6));
      ans.pb(mp(9,(cont-6)/6));
    }
  }
  if(cycle.size() == 1 && grau3 == 0){
    if(cycle[0] == cont && cont%6 == 0){ // 0
     // printf("Found 0 starting at %d\n",i);
      ans.pb(mp(0,(cont-6)/6));
    }
  }
  if(cycle.size() == 0 && grau3 == 0){
    if((cont-3)%2 == 0){ // 1
     // printf("Found 1 starting at %d\n",i);
      ans.pb(mp(1,(cont-3)/2));
    }
    if((cont-6)%5 == 0){ // 2 ou 5
      //printf("Found 2 or 5 starting at %d\n",i);
      ans.pb(mp(2,(cont-6)/5));
      ans.pb(mp(5,(cont-6)/5));
    }
    if((cont-4)%3 == 0){ // 7
     // printf("Found 7 starting at %d\n",i);
      ans.pb(mp(7,(cont-4)/3));
    }
  }
  if(cycle.size() == 0 && grau3 == 1){
    //printf("Searching in grade 3\n");
    vi sons;
    for(int j = 0; j < graph[i].size(); j++){
    //  printf("%d is son\n",graph[i][j]);
      sons.pb(subsize[graph[i][j]]);
    }
    sort(sons.begin(),sons.end());
    if((cont-6)%5 == 0){ // 3
      int k = (cont-6)/5;
     // printf("Sons[%d] = %d %d %d\n",sons.size(),sons[0],sons[1], sons[2]);
      if(sons[0] == 1+k && sons[1] == sons[2] && sons[2] == 2*k+2){
      //  printf("Found 3 starting at %d\n",i);
        ans.pb(mp(3,k));
      }
    }
    if((cont-5)%4 == 0){ // 4
      int k = (cont-5)/4;
      if(sons[0] == sons[1] && sons[1] == 1+k && sons[2] == 2*k+2){
       // printf("Found 4 starting at %d\n",i);
        ans.pb(mp(4,k));
      }
    }
  }
}

int main(){
  int T;
  //FILE *pFile = fopen("input.txt","w");
  scanf("%d",&T);
  //fprintf(pFile,"%d\n",T);
  for(int caso = 1; caso <= T; caso++){
    if(caso > 1) printf("\n");
    scanf("%d %d",&n,&m);
    
    //fprintf(pFile,"Case %d:\n%d %d\n",caso,n,m);
    for(int i = 0; i <= n; i++) graph[i].clear();
    for(int i = 0; i < m; i++){
      int a, b;
      scanf("%d %d",&a,&b);
      //fprintf(pFile,"%d %d\n",a,b);
      graph[a].pb(b);
      graph[b].pb(a);
    }
    solve();
    sort(ans.begin(),ans.end());
    printf("Case %d: %d\n",caso,ans.size());
    for(int i = 0; i < ans.size(); i++){
      printf("%d %d\n",ans[i].F,ans[i].S);
    }
  }  
  //fclose(pFile);
  return 0;
}
