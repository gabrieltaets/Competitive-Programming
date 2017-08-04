#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, x, y, z;
  scanf("%d %d %d %d %d",&n,&m,&x,&y,&z);
  int max3 = z*3, max2 = y*2;
  if(n >= max3){
    n -= max3;
    z = 0;
  }
  else {
    z -= n/3;
    n %= 3;
  }
  if(n >= max2){
    n -= max2;
    y = 0;
  }
  else {
    y -= n/2;
    n %= 2;
  }
  if(n + m <= x + y + z) printf("Yes\n");
  else printf("No\n");
  return 0;
}