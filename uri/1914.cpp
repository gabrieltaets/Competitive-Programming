#include <bits/stdc++.h>
using namespace std;
int main(){
  int qt;
  scanf("%d",&qt);
  while(qt--){
    string nome1, nome2, cho1, cho2;
    cin >> nome1 >> cho1 >> nome2 >> cho2;
    int sho1, sho2;
    cin >> sho1 >> sho2;
    if((sho1+sho2)&1){
      if(cho2 == "IMPAR") cout << nome2;
      else cout << nome1;
    }
    else {
      if(cho2 == "PAR") cout << nome2;
      else cout << nome1;
    }
    cout << endl;
  }
  return 0;
}