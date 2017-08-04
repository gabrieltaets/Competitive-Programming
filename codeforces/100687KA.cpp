#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M, X, Y, Z;
  scanf("%d %d %d %d %d",&N,&M,&X,&Y,&Z);
  getchar();
  char grid[20][35];
  for(int i = 0; i < 16; i++) gets(grid[i]);
  string seq;
  cin >> seq;
  pair<int,int> head, exit;
  for(int i = 0; i < 16; i++) for(int j = 0; j < 32; j++){
    if(grid[i][j] == ':') head = make_pair(i,j);
    if(grid[i][j] == 'E') exit = make_pair(i,j);
  }
  for(int i = 0; i < seq.size(); i++){
    if(seq[i] == '<') head.second--;
    if(seq[i] == '>') head.second++;
    if(seq[i] == '^') head.first--;
    if(seq[i] == 'v') head.first++;
  }
  if(head == exit) printf("Yes\n");
  else printf("No\n");
  return 0;
}