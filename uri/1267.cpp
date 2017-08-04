#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, d;
  while(scanf("%d %d",&n,&d) && (n+d)){
    int v[n], x, flag = 0;
    memset(v,1,sizeof v);
    while(d--){
      for(int i = 0; i < n; i++){
        scanf("%d",&x);
        v[i] &= x;
      }
    }
    for(int i = 0; i < n; i++) flag |= v[i];
    printf("%s\n",flag?"yes":"no");
  }
  return 0;
}