#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int main(){
  int n, m, k, t, c;
  scanf("%d %d %d %d",&n,&m,&k,&t);
  deque<ii> vault;
  deque<int> ppl;
  for(int i = 0; i < n; i++){
    scanf("%d",&c);
    ppl.push_back(c);
  }
  for(int i = 0; i < m; i++){
    scanf("%d",&c);
    vault.push_back(ii(c,k));
  }
  sort(ppl.begin(),ppl.end());
  sort(vault.begin(),vault.end());
  int res = 0;
  for(int i = 0; i < ppl.size(); i++){
    while(!vault.empty()){
      int cap = vault.front().second;
      int pos = vault.front().first;
      if(!cap) vault.pop_front();
      else if(ppl[i] - pos > t) vault.pop_front();
      else break;
    }
    if(vault.empty()) break;
    if(abs(ppl[i] - vault.front().first) <= t){
      res++;
      vault.front().second--;
    }
  }
  printf("%d\n",res);
  return 0;
}