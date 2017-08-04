#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    string a, b;
    cin >> a >> b;
    int cost = 0;
    for(int i = 0; i < a.size(); i++){
      if(a[i] == b[i]) continue;
      if(a[i] < b[i]) {
        cost += b[i]-a[i];
      }
      else {
        cost += 'z' - a[i] + b[i] - 'a' + 1;
      }
    }
    printf("%d\n",cost);
  }
  return 0;
}