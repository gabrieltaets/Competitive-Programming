#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string str;
int n, k;

int solve(){
  int maxla = 1, maxlb = 1, conta = 0, contb = 0, left = k, inia = 0, inib = 0, fima, fimb;
  for(int i = 0; i < n; i++){
    if(!conta && str[i] == 'b'){
      contb++;
      continue;
    }
    if(str[i] == 'a') {
      if(conta && i && str[i-1] == 'b') inia = i;
      conta++;
    }
    else {
      contb = 1;
      for(int j = i+1; j < n; j++){
        if(str[i] == 'b') contb++;
        else {
          i = j;
          break;
        }
      }
      if(left >= contb){
        left -= contb;
        conta += contb;
        maxla = max(maxla,conta);
      }
      else {
        conta += left;
        if(conta > maxla){
          maxla = conta;
          fima = inia;
        }
        conta = 0;
        left = k;
      }
    }
    if(i == n-1 && left) {
      conta += min(contb,left);
      inia -= min(contb,left);
    }
    if(conta > maxla){
      fima = inia;
      maxla = conta;
    }
  }
  cout << "Best for a: " << str.substr(fima,maxla) << endl;
  left = k;
  contb = 0;
  conta = 0;
  for(int i  = 0; i < n; i++){
    if(!contb && str[i] == 'a'){
      conta++;
      continue;
    }
    if(str[i] == 'b') {
      if(contb && i && str[i-1] == 'a') inib = i;
      contb++;
    }
    else {
      conta = 1;
      for(int j = i+1; j < n; j++){
        if(str[i] == 'a') conta++;
        else {
          i = j;
          break;
        }
      }
      if(left >= conta){
        left -= conta;
        contb += conta;
        maxlb = max(maxlb,contb);
      }
      else {
        contb += left;
        maxlb = max(maxlb,contb);
        contb = 0;
        left = k;
      }
    }
    if(i == n-1 && left) {
      contb += min(conta,left);
      inib -= min(conta,left);
    }
    if(contb > maxlb){
      maxlb = contb;
      fimb = inib;
    }
  }
  cout << "Best for b: " << str.substr(fimb,maxlb) << endl;
  return max(maxla,maxlb);
}

int main(){
  scanf("%d %d",&n,&k);
  cin >> str;
  cout << solve() << endl;
  return 0;
}