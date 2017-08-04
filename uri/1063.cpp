#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(scanf("%d",&n) && n){
    char x;
    vector<char> in(n);
    queue<char> q;
    stack<char> s;
    for(int i = 0; i < n; i++) scanf(" %c",&in[i]);
    for(int i = 0; i < n; i++) {
      scanf(" %c",&x);
      q.push(x);
    }
    for(int i = 0; i < n; i++){
      s.push(in[i]);
      printf("I");
      while(!s.empty() && !q.empty() && s.top() == q.front()){
        s.pop();
        q.pop();
        printf("R");
      }
    }
    if(!s.empty() || !q.empty()) printf(" Impossible\n");
    else putchar('\n');
  }
  return 0;
}