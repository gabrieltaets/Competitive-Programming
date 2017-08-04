#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d ",&n);
  while(n--){
    char str[60];
    gets(str);
    for(int i = 0; i < strlen(str); i++){
      if(!i && str[i] != ' ') putchar(str[i]);
      else if(str[i-1] == ' ' && str[i] != ' ') putchar(str[i]);
    }
    putchar('\n');
  }
  return 0;
}