#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  int freq[300];
  memset(freq,0,sizeof freq);
  char c;
  set<char> s;
  int exc = 0, zeros = 0;
  for(int i = 0; i < n; i++){
    scanf(" %c",&c);
    freq[c]++;
    if(freq[c] > 1){
      freq[c] = 1;
      exc++;
    }
  }
  for(int i = 'a'; i <= 'z'; i++){
    if(!freq[i]) zeros++;
  }
  if(exc > zeros) printf("-1\n");
  else printf("%d\n",exc);
  return 0;
}