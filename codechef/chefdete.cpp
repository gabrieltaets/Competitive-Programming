#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int p[N+1];
  memset(p,0,sizeof p);
  for(int i = 1; i <= N; i++){
    int x;
    cin >> x;
    p[x] = 1;
  }
  bool f = false;
  for(int i = 1; i <= N; i++){
    if(!p[i]){
      if(f) putchar(' ');
      printf("%d",i);
      f = true;
    }
  }
  printf("\n");
  return 0;
}