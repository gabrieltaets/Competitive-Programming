#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  while(scanf("%d %d",&n,&m)!=EOF && n+m){
    string str(to_string(n+m));
    for(int i = 0; i < str.size(); i++){
      if(str[i] == '0') {
        str.erase(str.begin()+i);
        i--;
      }
    }
    if(str.empty()) str = "0";
    cout << str << endl;
  }
  return 0;
}
