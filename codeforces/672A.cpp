#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  string str;
  for(int i = 1; i <= n; i++){
    str += to_string(i);
  }
  printf("%c\n",str[n-1]);
  return 0;
}