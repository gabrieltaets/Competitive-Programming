#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  vector<int> par;
  vector<int> impar;
  for(int i = 0; i < 15; i++){
    scanf("%d",&x);
    if(x%2==0) par.push_back(x);
    else impar.push_back(x);
    if(par.size()==5){
      for(int j = 0; j < 5; j++) printf("par[%d] = %d\n",j,par[j]);
      par.clear();
    }
    if(impar.size()==5){
      for(int j = 0; j < 5; j++) printf("impar[%d] = %d\n",j,impar[j]);
      impar.clear();
    }
  }
  if(!impar.empty())
    for(int i = 0; i < impar.size(); i++) printf("impar[%d] = %d\n",i,impar[i]);
  if(!par.empty())
    for(int i = 0; i < par.size(); i++) printf("par[%d] = %d\n",i,par[i]);
  return 0;
}