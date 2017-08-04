#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  getchar();
  while(n--){
    string str;
    getline(cin,str);
    int freq[300], mf = 0;
    memset(freq,0,sizeof freq);
    for(int i = 0; i < str.size(); i++){
      if(isalpha(str[i]))
        freq[tolower(str[i])]++;
      mf = max(mf,freq[tolower(str[i])]);
    }
    for(int i = 'a'; i <= 'z'; i++){
      if(freq[i] == mf) putchar(i);
    }
    putchar('\n');
  }
  return 0;
}