#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  for(int k = 1; k <= n; k++){
    deque <int> orig, aux, finish;
    int t, x;
    cin >> t;
    for(int i = 0; i < t; i++){
      scanf("%d",&x);
      aux.push_back(x);
      orig.push_back(x);
    }
    //1st test
    finish.push_back(orig[0]);
    orig.pop_front();
    bool chg = true, ans;
    while(!orig.empty() && chg){
      chg = false;
      if(orig.front() == finish.front() - 1){
        finish.push_front(orig.front());
        orig.pop_front();
        chg = true;
      }
      if(orig.back() == finish.front() - 1){
        finish.push_front(orig.back());
        orig.pop_back();
        chg = true;
      }
      if(orig.front() == finish.back() + 1){
        finish.push_back(orig.front());
        orig.pop_front();
        chg = true;
      }
      if(orig.back() == finish.back() + 1){
        finish.push_back(orig.back());
        orig.pop_back();
        chg = true;
      }
    }
    ans = orig.empty();
    finish.clear();
    //2nd test
    orig = aux;
    finish.push_back(orig.back());
    orig.pop_back();
    chg = true;
    while(!orig.empty() && chg){
      chg = false;
      if(orig.front() == finish.front() - 1){
        finish.push_front(orig.front());
        orig.pop_front();
        chg = true;
      }
      if(orig.back() == finish.front() - 1){
        finish.push_front(orig.back());
        orig.pop_back();
        chg = true;
      }
      if(orig.front() == finish.back() + 1){
        finish.push_back(orig.front());
        orig.pop_front();
        chg = true;
      }
      if(orig.back() == finish.back() + 1){
        finish.push_back(orig.back());
        orig.pop_back();
        chg = true;
      }
    }
    ans = ans || orig.empty();
   // printf("Finished Stack: \n");
  //  for(int j = 0; j < finish.size(); j++) printf("%d ",finish[j]);
   // putchar('\n');
    if(ans) printf("Case #%d: yes\n",k);
    else {
      //printf("Remaining Stack:\n");
      //for(int j = 0; j < finish.size(); j++) printf("%d ",orig[j]);
     // putchar('\n');
      printf("Case #%d: no\n",k);
    }
  }
  return 0;
}