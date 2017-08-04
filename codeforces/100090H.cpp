#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  int v[n], m = 0;
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
    m = max(m,v[i]);
  }
  int k;
  for(k = 0; k < 32; k++){
    if((1<<k)-1 == m){
      printf("Mike\n");
      break;
    }
  }
  if(k==32) printf("Constantine\n");  
  return 0;
}