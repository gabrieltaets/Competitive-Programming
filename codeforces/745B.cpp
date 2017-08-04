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

int main(){
  int n, m;
  cin >> n >> m;
  char grid[510][510];
  ii tl(INF,INF), br(-1,-1);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf(" %c",&grid[i][j]);
      if(grid[i][j] != 'X') continue;
      tl.F = min(tl.F,i); // TOP
      tl.S = min(tl.S,j); // LEFT
      br.F = max(br.F,i); // BOTTOM 
      br.S = max(br.S,j); // RIGHT
    }
  }
  for(int i = tl.F; i <= br.F; i++){
    for(int j = tl.S; j <= br.S; j++){
      if(grid[i][j] != 'X'){
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
	return 0;
}
