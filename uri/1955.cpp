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
bool graph[1010][1010];
int color[1010];
int n;
bool bfs(int s){
  color[s] = 1;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int a = q.front(), c = color[a];
    q.pop();
    for(int i = 0; i < n; i++){
      if(graph[a][i]) continue;
      if(color[i] == color[a]) return false;
      if(color[i]) continue;
      color[i] = (color[a] == 1 ? 2 : 1);
      q.push(i);
    }
  }
  for(int i = 0; i < n; i++) if(!color[i]) return bfs(i);
  return true;
}
int main(){
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d",&graph[i][j]);
    }
  }
  if(bfs(0)) printf("Bazinga!\n");
  else printf("Fail!\n");
  return 0;
}
