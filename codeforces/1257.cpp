#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, L;
  scanf("%d",&N);
  while(N--){
    scanf("%d",&L);
    int hash = 0;
    string str;
    for(int j = 0; j < L; j++){
      cin >> str;
      for(int i = 0; i < str.size(); i++){
        hash += str[i] - 'A' + i + j;
      }
    }
    cout << hash << endl;
  }
  return 0;
}