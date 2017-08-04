#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); i++){
    if(i+25>str.size()) break;
    int freq[30];
    memset(freq,0,sizeof freq);
    bool flag = false;
    for(int j = i; j < i+26; j++){
      freq[str[j]-'?']++;
      if(str[j] != '?' && freq[str[j]-'?']>1){
        flag = true;
        break;
      }
    }
    if(flag) continue;
    vector<char> need;
    for(int j = 2; j < 28; j++){
      if(freq[j] == 0) {
        need.pb(j+'?');
         //printf("need a %c\n",j+'?');
      }
    }
    if(need.size() > freq[0]) continue;
    int k = 0;
    for(int j = 0; j < 26; j++){
      if(str[i+j] != '?') continue;
      char c = 'A';
      if(k < need.size()) c = need[k++];
      str[i+j] = c;
      if(k >= need.size()) k = 0;
    }
    for(int j = 0; j < str.size(); j++){
      if(str[j] != '?') continue;
      char c = 'A';
      if(k < need.size()) c = need[k++];
      str[j] = c;
      if(k >= need.size()) k = 0;
    }
    cout << str << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
