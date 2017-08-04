#include <bits/stdc++.h>
using namespace std;
vector<int> s;

int solve(){
  
}

int main(){
  int n, c, t, cont = 0;
  bool flag = false;
  scanf("%d",&n);
  
  for(int i = 0; i < n; i++){
    scanf("%d",&c);
    s.push_back(c);
    
    
    if(!s.empty()){
      if(s.top() == c){
        s.pop();
        if(!flag) cont++;
        flag = true;
      }
      else {
        t = s.top(); s.pop();
        if(!s.empty() && s.top() == c){
          s.pop();
          if(!flag) cont++;
          flag = true;
        }
        else {
          s.push(t);
          s.push(c);
          flag = false;
        }
      }
    }
    else {
      s.push(c);
      flag = false;
    }
  }
  printf("%d\n",cont+s.size());
}