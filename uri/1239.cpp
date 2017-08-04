#include <bits/stdc++.h>
using namespace std;
int main(){
  string str;
  while(getline(cin,str)){
    string res;
    bool bold = false, under = false;
    for(int i = 0; i < str.size(); i++){
      if(str[i] == '_'){
        res += (under ? "</i>" : "<i>");
        under = !under;
      }
      else if(str[i] == '*'){
        res += (bold ? "</b>":"<b>");
        bold = !bold;
      }
      else res.push_back(str[i]);
    }
    cout << res << endl;
  }
  return 0;
}