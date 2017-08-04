#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  getchar();
  while(n--){
    char ln[3000], buffer[60], *ptr;
    string str[56];
    ptr = gets(ln);
    int i = 0;
    while(ptr-ln<strlen(ln) && sscanf(ptr,"%s",buffer)==1){
      ptr += strlen(buffer)+1;
      str[i] = buffer;
      i++;
    }
    bool flag = false;
    for(int j = 50; j > 0; j--){
      for(int k = 0; k < i; k++){
        if(str[k].size() == j){
          if(flag) cout << " ";
          cout << str[k];
          flag = true;
        }
      }
    }
    cout << endl;
  }
  return 0;
}