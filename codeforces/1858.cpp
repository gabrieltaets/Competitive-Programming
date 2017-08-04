#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m = 100, mix = 1, x;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++){
    scanf("%d",&x);
    if(x < m){
      m = x;
      mix = i;
    }
  }
  printf("%d\n",mix);
  return 0;
}