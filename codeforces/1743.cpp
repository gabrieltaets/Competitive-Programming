#include <bits/stdc++.h>
using namespace std;
int main(){
  int v1[5],v2[5];
  for(int i = 0; i < 5; i++) scanf("%d",&v1[i]);
  for(int i = 0; i < 5; i++) scanf("%d",&v2[i]);
  int i;
  for(i = 0; i < 5; i++) if(v1[i] == v2[i]) break;
  printf("%c\n",(i == 5 ? 'Y' : 'N'));
  return 0;
}