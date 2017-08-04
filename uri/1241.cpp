#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    string str1, str2;
    cin >> str1 >> str2;
    if(str1.size() >= str2.size() && str1.substr(str1.size()-str2.size()) == str2) printf("encaixa\n");
    else printf("nao encaixa\n");
  }
  return 0;
}