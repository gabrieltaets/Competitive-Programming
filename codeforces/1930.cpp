#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, sum = 0;
  for(int i = 0; i < 4; i++){
    scanf("%d",&x);
    sum += x;
  }
  cout << sum-3 << endl;
  return 0;
}