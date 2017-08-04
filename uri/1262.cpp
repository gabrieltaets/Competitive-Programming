#include <bits/stdc++.h>
using namespace std;
int main(){
  string str;
  int n;
  while(cin >> str){
    cin >> n;
    int r = 0, w = 0, cycles = 0;
    for(int i = 0;i < str.size(); i++){
      if(str[i] == 'R'){
        cycles += w;
        w = 0;
        r++;
      }
      else {
        cycles += ceil((double)r/n);
        r = 0;
        w++;
      }
    }
    cycles += w + ceil((double)r/n);
    cout << cycles << endl;
  }
  return 0;
}
