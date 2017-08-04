#include <bits/stdc++.h>
using namespace std;
int freq[300];
int fat[1010];
int main(){
  string str;
  fat[0] = 1;
  for(long long i = 1; i <= 1000; i++) fat[i] = (fat[i-1LL]*i)%1000000007;
  while(cin >> str){
    memset(freq,0,sizeof freq);
    int cont = 0;
    for(int i = 0; i < str.size(); i++){
      if(!freq[str[i]]) cont++;
      freq[str[i]]++;
    }
    int ans = 1;
    for(int i = 'A'; i <= 'Z'; i++){
      ans = (ans*fat[freq[i]])%1000000007;
    }
    cout << fat[cont] << endl;
    cout << ans << endl;
    ans = fat[c]/ans;
    cout << ans << endl;
  }
  return 0;
}