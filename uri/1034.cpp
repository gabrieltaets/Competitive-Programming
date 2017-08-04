#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int pd[25][1000010];
vector<int> c;
int solve(int t, int l){
  if(!l) return 0;
  if(t == c.size()) return 0x3f3f3f3f;
  if(pd[t][l] != 0x3f3f3f3f) return pd[t][l];
  pd[t][l] = solve(t+1,l);
  if(c[t] <= l){
    pd[t][l] = min(pd[t][l],solve(t,l-c[t])+1);
  }
  return pd[t][l];
}
bool cmp(int a, int b){
  return b < a;
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; i++) for(int j = 0; j <= M; j++) pd[i][j] = 0x3f3f3f3f;
    for(int i = 0; i < N; i++) {
      int x, j;
      scanf("%d",&x);
      for(j = 1; j < c.size(); j++){
        if(x % c[j] == 0){
          
        }
      }
    }
    sort(c,c+N,cmp);
    printf("%d\n",solve(0,M));
  }
  return 0;
}