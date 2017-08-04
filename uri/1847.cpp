#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c;
  scanf("%d %d %d",&a,&b,&c);
  if((b < a && c >= b)||(a < b && c > b && c-b >= b-a)||(a > b && c < b && a-b > b-c)||(a == b && c > b)) printf(":)\n");
  else printf(":(\n");
  return 0;
}