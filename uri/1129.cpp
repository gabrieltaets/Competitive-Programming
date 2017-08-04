#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(scanf("%d",&n) && n){
    while(n--){
      int ans = -1, x;
      for(int i = 0; i < 5; i++){
        scanf("%d",&x);
        if(x <= 127) ans = ans == -1 ? i : -2;
      }
      printf("%c\n",ans>=0?'A'+ans:'*');
    }
  }
  
  return 0;
}