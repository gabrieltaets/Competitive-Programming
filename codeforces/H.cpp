#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  int v[n], cont = 0;
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
    if(v[i]&1) cont++;
  }
  if(cont == n) printf("Mike\n");
  else printf("Constantine\n");  
  return 0;
}