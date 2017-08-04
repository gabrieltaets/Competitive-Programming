#include <bits/stdc++.h>
using namespace std;
char img[27][27];
int ff[27][27], N;
int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

void floodfill(int r, int c){
  if (r < 1 || r > N || c < 1 || c > N) return; 
  if (img[r][c] != '1') return; 
  img[r][c] = '0'; 
  for (int d = 0; d < 8; d++)
    floodfill(r + dr[d], c + dc[d]);
}
int main(){
  int C=1;
  while(scanf("%d",&N)!=EOF){
    int cont = 0;
    getchar();
    for(int i = 0; i <= N+1; i++){
      img[0][i] = img[i][0] = img[N+1][i] = img[i][N+1] = '0';
    }
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        scanf(" %c",&img[i][j]);
      }
    }
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++){
      if(img[i][j] == '1'){
        floodfill(i,j);   
        ++cont;
      }
    }
    printf("Image number %d contains %d war eagles.\n",C++,cont);
  }
  return 0;
}