#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
 char _;
struct pair {
  int first, second;
  bool operator==(pair x){
    return (first==x.first && second==x.second);
  }
};
pair make_pair(int a, int b){
  pair x;
  x.first = a;
  x.second = b;
}
char grid[2510][2510];
pair lim[2510][2510][2];
int n, m, q;
int main(){
  //scanf("%d %d",&n,&m);
  scan(n); scan(m);
  for(int i = 0; i <= n+1; i++){
    lim[i][0][0] = make_pair(1,m);
    lim[i][0][1] = make_pair(1,n);
    lim[i][m+1][0] = make_pair(1,m);
    lim[i][m+1][1] = make_pair(1,n);
  }
  for(int j = 0; j <= m+1; j++){
    lim[0][j][0] = lim[n+1][j][0] = make_pair(1,m);
    lim[0][j][1] = lim[n+1][j][1] = make_pair(1,n);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      grid[i][j] = getchar();
      //scanf(" %c",&grid[i][j]);
      if(grid[i][j] == '#'){
        lim[i-1][j][1].second = i-1;
        lim[i+1][j][1].first = i+1;
        lim[i][j-1][0].second = j-1;
        lim[i][j+1][0].first = j+1;
      }
    }
    getchar();
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(grid[i][j] == '.'){
        if(grid[i-1][j] == '.') lim[i][j][1].first = lim[i-1][j][1].first;
        if(grid[i][j-1] == '.') lim[i][j][0].first = lim[i][j-1][0].first;
      }
      if(grid[n-i+1][m-j+1] == '.'){
        if(grid[n-i+2][m-j+1] == '.') lim[n-i+1][m-j+1][1].second = lim[n-i+2][m-j+1][1].second;
        if(grid[n-i+1][m-j+2] == '.') lim[n-i+1][m-j+1][0].second = lim[n-i+1][m-j+2][0].second;
      }
    }
  }
  //scanf("%d",&q);
  scan(q);
  int r1, r2, c1, c2;
  while(q--){
    scan(r1);
    scan(c1);
    scan(r2);
    scan(c2);
    //scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    if(r1 == r2 && c1 == c2) printf("YES\n");
    else {if(c1 == c2){
        if(lim[r1][c1][1] == lim[r2][c2][1]) printf("YES\n");
        else printf("NO\n");
      }
      else if(r1 == r2){
        if(lim[r1][c1][0] == lim[r2][c2][0]) printf("YES\n");
        else printf("NO\n");
      }
      else if((lim[r1][c2][0] == lim[r1][c1][0] && lim[r1][c2][1] == lim[r2][c2][1])
        || (lim[r2][c1][0] == lim[r2][c2][0] && lim[r2][c1][1] == lim[r1][c1][1]))
        printf("YES\n");
      else printf("NO\n");
    }
  }
  return 0;
}