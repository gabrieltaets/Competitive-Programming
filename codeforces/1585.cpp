#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, y, n;
  scanf("%d",&n);
  while(n--){
    scanf("%d %d",&x,&y);
    cout << (x*y)/2 << " cm2" << endl;    
  }
  return 0;
}