#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int x;
    scanf("%d",&x);
    if(x&1) printf("1\n");
    else printf("0\n");
  }
  return 0;
}