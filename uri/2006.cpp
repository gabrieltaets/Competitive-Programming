#include <bits/stdc++.h>
using namespace std;
int main(){
  int t, cont = 0;
  scanf("%d",&t);
  for(int i = 0; i < 5; i++){
    int x;
    scanf("%d",&x);
    if(x == t) cont++;
  }
  cout << cont << endl;
  return 0;
}