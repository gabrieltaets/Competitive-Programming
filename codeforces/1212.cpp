#include <bits/stdc++.h>
using namespace std;
int main(){
  string x, y;
  while(cin >> x >> y && (x != "0" || y != "0")){
    if(x.size() < y.size()) swap(x,y);
    int cont = 0, i = x.size()-1, j = y.size()-1;
    for(;j>=0;j--,i--){
      x[i] += y[j]-'0';
      if(x[i] > '9') {
        cont++;
        if(i) x[i-1]++;
      }
    }
    if(j != i && x[i] > '9') cont++;
    if(cont == 1) printf("1 carry operation.\n");
    else if(cont > 1) printf("%d carry operations.\n",cont);
    else printf("No carry operation.\n");
  }
  return 0;
}