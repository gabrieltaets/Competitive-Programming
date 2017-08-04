#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  while(T--){
    int num;
    cin >> num;
    int freq[10];
    memset(freq,0,sizeof freq);
    char str[10];
    for(int i = 1; i <= num; i++){
      sprintf(str,"%d",i);
      for(int j = 0; j < str[j]; j++){
        freq[str[j]-48]++;
      }
    }
    for(int i = 0; i < 9; i++) printf("%d ",freq[i]);
    printf("%d\n",freq[9]);
  }
  return 0;
}