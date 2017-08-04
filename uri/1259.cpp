#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  vector<int> par, impar;
  scanf("%d",&N);
  while(N--){
    int x;
    scanf("%d",&x);
    if(x&1) impar.push_back(-x);
    else par.push_back(x);
  }
  sort(par.begin(),par.end());
  sort(impar.begin(),impar.end());
  for(int i = 0; i < par.size(); i++) printf("%d\n",par[i]);
  for(int i = 0; i < impar.size(); i++) printf("%d\n",-impar[i]);
  return 0;
}