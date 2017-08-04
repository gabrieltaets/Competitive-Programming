#include <bits/stdc++.h>
using namespace std;
int main(){
  char d;
  while(scanf(" %c",&d) && d != '0'){
    string res, n;
    cin >> n;
    for(int i = 0; i < n.size(); i++){
      if(n[i] != d) res.push_back(n[i]);
    }
    int i;
    for(i = 0; i < res.size(); i++){
      if(res[i] != '0') break;
    }
    res = res.substr(i);
    if(res.empty()) res = "0";
    cout << res << endl;
  }
  return 0;
}