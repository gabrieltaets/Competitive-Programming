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
char grid[110][110];
int dist[110][110][5];
int w, h;
vii cow;
ii chg[] = {ii(1,0), ii(-1,0), ii(0,1), ii (0,-1) };

bool isValid(int i, int j){
  if(i < 0 || i >= h || j < 0 || j >= w || grid[i][j] == '*') return false;
  return true;
}

void print(){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      printf("%2d ",min(min(dist[i][j][0],dist[i][j][1]),min(dist[i][j][2],dist[i][j][3]))==INF?-1:min(min(dist[i][j][0],dist[i][j][1]),min(dist[i][j][2],dist[i][j][3])));
    }
    putchar('\n');
  }
}

bool canTurn(int o, int dir){
  switch(o){
    case 0:
      return dir != 1;
    case 1:
      return dir != 0;
    case 2:
      return dir != 3;
    case 3:
      return dir != 2;
  }
}

void bfs(ii source, ii sink){
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) for(int k = 0; k < 4; k++) dist[i][j][k] = INF;
  dist[source.F][source.S][0] = dist[source.F][source.S][1] = dist[source.F][source.S][2] = dist[source.F][source.S][3] = 0;
  queue<pair<ii,int> > q;
  q.push(mp(source,0));
  q.push(mp(source,1));
  q.push(mp(source,2));
  q.push(mp(source,3));
  while(!q.empty()){
    int x = q.front().F.F, y = q.front().F.S, o = q.front().S;
    q.pop();
    for(int i = 0; i < 4; i++){
      if(!canTurn(o,i)) continue;
      int dx = x+chg[i].F, dy = y+chg[i].S;
      if(isValid(dx,dy) && dist[dx][dy][i] > dist[x][y][o] + (o==i?0:1)){
        dist[dx][dy][i] = dist[x][y][o] + (o==i?0:1);
        q.push(mp(ii(dx,dy),i));
        //printf("Arrived at [%d][%d][%d] with distance %d\n",dx,dy,i,dist[dx][dy][i]);
      }
    }
  }
  //print();
}

int main(){
  while(scanf("%d %d",&w,&h)!=EOF){
    cow.clear();
    getchar();
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        grid[i][j] = getchar();
        if(grid[i][j] == 'C') cow.pb(mp(i,j));
      }
      getchar();
    }
    bfs(cow[0],cow[1]);
    printf("%d\n",min(min(dist[cow[1].F][cow[1].S][0],dist[cow[1].F][cow[1].S][1]),min(dist[cow[1].F][cow[1].S][2],dist[cow[1].F][cow[1].S][3])));
  }
  return 0;
}
