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

int L, ini, fin, m, v;
char bomb[1005][1005];
int dist[1005][105];

int bfs(){
  for(int i = 0; i < 1005; i++) for(int j = 0; j < 105; j++) dist[i][j] = 0x3f3f3f3f;
  dist[ini][0] = 0;
  queue<ii> q;
  q.push(mp(ini,0));
  while(!q.empty()){
    int a = q.front().F, t = q.front().S; q.pop();
    if(a == fin) return dist[a][t];
    if(t == m-1) return -1;
    for(int i = 0; i < v; i++){
      if(a+i <= L){
        if(bomb[a+i][t] == '.' && bomb[a+i][t+1] == '.'){
          if(dist[a+i][t+1] == 0x3f3f3f3f)
            q.push(mp(a+i,t+1));
          dist[a+i][t] = min(dist[a+i][t],dist[a][t]+i);
          dist[a+i][t+1] = min(dist[a+i][t+1],dist[a][t]+i);
        }
        if(bomb[a+i][t] == 'X') break;
      }
    }
    for(int i = 1; i < v; i++){
      if(a-i >= 0){
        if(bomb[a-i][t] == '.' && bomb[a-i][t+1] == '.'){
          if(dist[a-i][t+1] == 0x3f3f3f3f)
            q.push(mp(a-i,t+1));
          dist[a-i][t] = min(dist[a-i][t],dist[a][t]+i);
          dist[a-i][t+1] = min(dist[a-i][t+1],dist[a][t]+i);
        }
        if(bomb[a-i][t] == 'X') break;
      }
    }
  }
}

int main(){
  while(scanf("%d",&L) && L){
    scanf("%d %d",&ini,&fin);
    scanf("%d %d",&m,&v);
    getchar();
    for(int i = 0; i < m; i++){
      gets(bomb[i]);
    }
    printf("%d\n",bfs());
  }
  return 0;
}
