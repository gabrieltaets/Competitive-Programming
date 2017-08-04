
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
char grid[60][60];
bool vis[60][60];
bool ans;
int N;
void floodfill(int x, int y){
  if(vis[x][y]) return;
  vis[x][y] = true;
  for(int i = -1; i <= 1; i++){
    for(int j = -1; j <= 1; j++){
      if(x+i < 0 || x+i >= N || y+j < 0 || y+j >= N) continue;
      if(!i && !j) continue;
      if(grid[x+i][y+j] == '4') floodfill(x+i,y+j);
      else if(abs(i) == abs(j) && grid[i+x][y+j] != '1') {
        ans = false;
      }
      else if(abs(i) != abs(j) && grid[i+x][y+j] != '2') {
        ans = false;
      }
      vis[i+x][y+j] = true;
    }
  }
}
int main(){
  cin >> N;
  ans = true;
  memset(vis,false,sizeof vis);
  ii ul(0x3f3f3f3f,0x3f3f3f3f), dr(-1,-1);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> grid[i][j];
      if(grid[i][j] == '4'){
        ul.F = min(ul.F,i);
        ul.S = min(ul.S,j);
        dr.F = max(dr.F,i);
        dr.S = max(dr.S,j);
      }
    }
  }
  if(dr == ii(-1,-1)){
    printf("No\n");
    return 0;
  }
  for(int i = ul.F; i <= dr.F; i++){
    for(int j = ul.S; j <= dr.S; j++){
      if(grid[i][j] != '4'){
        printf("No\n");
        return 0;
      }
    }
  }
  floodfill(ul.F,ul.S);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(grid[i][j] == '3') ans = false;
      if(!vis[i][j] && grid[i][j] != '0') ans = false;
    }
  }
  printf("%s\n",ans?"Yes":"No");
  return 0;
}