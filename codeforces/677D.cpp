#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int n, m, p;
vii pos[100000];
ll pd[350][350];
bool memo[350][350];
int grid[350][530];

inline int dist(int a, int b, int c, int d){
  return abs(abs(c-a)+abs(d-b));
}

ll solve(int x, int y, int nc){
  if(x == 0 || y == 0 || x == n+1 || y == m+1) return 0x3f3f3f3f3f3f3f3fLL;
  if(nc == p+1) return 0;
  if(pd[x][y] != 0x3f3f3f3f3f3f3f3fLL) return pd[x][y];
  for(int i = 0; i < pos[nc].size(); i++){
    pd[x][y] = min(pd[x][y],solve(pos[nc][i].first,pos[nc][i].second,nc+1)+dist(x,y,pos[nc][i].first,pos[nc][i].second));
  }
  printf("Visted (%d,%d)\n",x,y);
  return pd[x][y];
}

int main(){
  cin >> n >> m >> p;
  for(int i = 0; i < 350; i++) for(int j = 0; j < 350; j++) pd[i][j] = 0x3f3f3f3f3f3f3f3fLL;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> grid[i][j];
      pos[grid[i][j]].pb(ii(i,j));
    }
  }
  cout << solve(1,1,1) << endl;
  return 0;
}