#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  while(scanf("%d %d",&n,&m)!=EOF){
    if(n > m) swap(n,m);
    int cuts = m-1;
    cuts += (m*(n-1));
    printf("%d\n",cuts);
  }
  return 0;
}