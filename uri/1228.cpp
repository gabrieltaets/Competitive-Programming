#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin >> n){
    int x[n], p[n], cont = 0;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++){
      int j;
      for(j = 0; j < n; j++){
        if(p[j] == x[i]) break;
      }
      for(; j > i; j--){
        swap(p[j],p[j-1]);
        cont++;
      }
    }
    cout << cont << endl;
  }  
  return 0;
}
