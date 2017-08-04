#include <bits/stdc++.h>
#define UM 1000001
#define DOIS 1000002
#define TRES 1000003
using namespace std;
int n, m, adj[4][4];
long long dist[1000010];
vector<int> v[1000010];
char tab[1005][1005];

long long int BFS(int s){
  memset(dist,0x3f3f3f3f,sizeof dist);
  dist[s] = 0LL;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    //puts("TESTE");
    int a = q.front(); q.pop();
    for(int i = 0; i < v[a].size(); i++){
      if(dist[v[a][i]] == 0x3f3f3f3f3f3f3f3fLL){
        q.push(v[a][i]);
        if((a == UM || a == DOIS || a == TRES)&&(v[a][i] == UM || v[a][i] == DOIS || v[a][i] == TRES)){
          if(adj[a-1000000][v[a][i]-1000000]) dist[v[a][i]] = dist[a]+1LL;
        }
        else dist[v[a][i]] = dist[a]+1LL;
        //printf("dist de %d ate %d = %d\n",s,v[a][i],dist[v[a][i]]);
      }
    }
  }
  return dist[UM] + dist[DOIS] + dist[TRES];
}

int main(){
  cin >> n >> m;
  memset(adj,0,sizeof adj);
  for(int i = 0; i <= n+1; i++) tab[i][0] = tab[i][m+1] = '#';
  for(int i = 0; i <= m+1; i++) tab[0][i] = tab[n+1][i] = '#';
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      scanf(" %c",&tab[i][j]);
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      //printf("Currently analyzing tab[%d][%d] (%c)\n",i,j,tab[i][j]);
      if(tab[i][j] == '.'){
        for(int k = -1; k <= 1; k++){
          for(int l = -1; l <= 1; l++){
            if(((bool)k)^((bool)l)){
              //printf("k=%d l=%d\n",k,l);
              //puts("TESTE");
              if(tab[i+k][j+l] == '.'){
                //printf("inserting %d to %d\n",(i+k(i-1)*1000+j-1);
                v[(i-1)*1000+j-1].push_back((i+k-1)*1000+j+l-1);
              }
              else if(tab[i+k][j+l] == '1'){
                //printf("inserting %d to 1\n",(i-1)*1000+j-1);
                v[(i-1)*1000+j-1].push_back(UM);
                v[UM].push_back((i-1)*1000+j-1);
              }
              else if(tab[i+k][j+l] == '2'){
                //printf("inserting %d to 2\n",(i-1)*1000+j-1);
                v[(i-1)*1000+j-1].push_back(DOIS);
                v[DOIS].push_back((i-1)*1000+j-1);
              } 
              else if(tab[i+k][j+l] == '3'){
                //printf("inserting %d to 3\n",(i-1)*1000+j-1);
                v[(i-1)*1000+j-1].push_back(TRES);
                v[TRES].push_back((i-1)*1000+j-1);
              }
            }
          }
        }
      }
      else if(tab[i][j] != '#'){
        for(int k = -1; k <= 1; k++){
          for(int l = -1; l <= 1; l++){
            if((bool)k^(bool)l){
              if(tab[i][j] == '1' && tab[i+k][j+l] == '2') {
                adj[1][2] = 1;
                v[UM].push_back(DOIS);
              }
              if(tab[i][j] == '1' && tab[i+k][j+l] == '3') {
                adj[1][3] = 1;
                v[UM].push_back(TRES);
              }
              if(tab[i][j] == '2' && tab[i+k][j+l] == '1') {
                adj[2][1] = 1;
                v[DOIS].push_back(UM);
              }
              if(tab[i][j] == '3' && tab[i+k][j+l] == '1') {
                adj[3][1] = 1;
                v[TRES].push_back(UM);
              }
              if(tab[i][j] == '2' && tab[i+k][j+l] == '3') {
                adj[2][3] = 1;
                v[DOIS].push_back(TRES);
              }
              if(tab[i][j] == '3' && tab[i+k][j+l] == '2') {
                adj[3][2] = 1;
                v[TRES].push_back(DOIS);
              }
            }
          }
        }
      }
    }
  }
  
  //printf("INF=%d\n",0x3f3f3f3f);
  long long int ans = 0x3f3f3f3f3f3f3f3fLL;// = min(BFS(UM,DOIS)+BFS(DOIS,TRES),min(BFS(UM,TRES)+BFS(TRES,DOIS),BFS(DOIS,UM)+BFS(UM,TRES)));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      ans = min(ans,BFS(1000*i+j));
    }
  }
  cout << (ans >= 0x3f3f3f3f3f3f3f3fLL ? -1LL : (ans > 0LL ? ans-3LL : ans )) << endl;
  return 0;
}