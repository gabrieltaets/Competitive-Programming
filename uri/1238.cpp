#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    string str1, str2, res;
    cin >> str1 >> str2;
    for(int i = 0; i < max(str1.size(),str2.size()); i++){
      if(i < str1.size()) res.push_back(str1[i]);
      if(i < str2.size()) res.push_back(str2[i]);
    }
    cout << res << endl;
  }
  return 0;
}