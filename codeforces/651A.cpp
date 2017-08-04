#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, s=0;
  cin >> a >> b;
  if(a == b && a == 1) {
    cout << 0 << endl;
    return 0;
  }
  while(a && b){
    if(b > a) swap(a,b);
    b++;
    a-=2;
    s++;
  }
  cout << s << endl;
  return 0;
}