#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d ",&n);
  while(n--){
    string str;
    getline(cin,str);
    reverse(str.begin(),str.begin()+str.size()/2);
    reverse(str.begin()+str.size()/2, str.end());
    cout << str << endl;
  }
  return 0;
}