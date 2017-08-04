#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, t;
  scanf("%d",&n);
  while(n--){
    scanf("%d",&t);
    int s[t];
    for(int i = 0; i < t; i++) scanf("%d",&s[i]);
    int cont = 0;
    for(int i = 0; i < t; i++){
      char p;
      scanf(" %c",&p);
      if(p == 'J' && s[i] > 2) cont++;
      else if(p == 'S' && s[i] <= 2) cont++;
    }
    cout << cont << endl;
  }
  return 0;
}