#include <bits/stdc++.h>
using namespace std;
int main(){
  string num;
  while(cin >> num && num[0] != '-'){
    if(num[0] != '0') printf("0x%X\n",stoi(num));
    else printf("%d\n",stoi(num.substr(2),NULL,16));
  }
  return 0;
}