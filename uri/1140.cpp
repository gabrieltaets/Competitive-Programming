#include <bits/stdc++.h>
using namespace std;
int main(){
  char ln[3000], buffer[60], *ptr;
  while((ptr = gets(ln))!=NULL && *ptr != '*'){
    //cout << "-> " << string(ln) << endl;
    string str[56];
    int i = 0;
    while(ptr-ln<strlen(ln) && sscanf(ptr,"%s",buffer)==1){
      ptr += strlen(buffer)+1;
      str[i] = buffer;
      i++;
    }
    bool flag = true;
    for(int j = 1; j < i; j++){
      if(tolower(str[j][0]) != tolower(str[j-1][0])) flag = false;
    }
    printf("%c\n",flag?'Y':'N');
  }
  return 0;
}