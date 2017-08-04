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

int freq[50010][30];
void process(string str){
  for(int i = 0; i < str.size(); i++){
    for(int j = 0; j < 30; j++){
      freq[i+1][j] += freq[i][j];
    }
    if(str[i] == '?') {
      freq[i+1][29] = freq[i][29]+1;
      continue;
    }
    freq[i+1][str[i]-'A']++;
    //printf("freq[%d][%c]=%d\n",i+1,str[i],freq[i+1][str[i]-'A']);
  }
  //for(int i = 0; i < 26; i++){
   // printf("Until the end, char %c appears %d times\n",i+'A',freq[str.size()][str[i]-'A']);
  //}
}

int main(){
  string str;
  cin >> str;
  if(str.size() < 26) {
    cout << -1 << endl;
    return 0;
  }
  process(str);
  for(int i = 1; i <= str.size()-25; i++){
    bool flag = false;
    vi need;
    for(int j = 0; j < 26; j++){
      //printf("freq[%d][%c]=%d  freq[%d][%c] =%d\n",i+25,j+'A',freq[i+25][j],i-1,j+'A',freq[i-1][j]);
     // printf("From %d to %d, char %c appears %d times\n",i,i+25,j+'A',freq[i+25][j]-freq[i-1][j]);
      if(freq[i+25][j]-freq[i-1][j]>1) {
        flag = true;
      //  printf("From %d to %d, char %c appears %d times\n",i,i+25,j+'A',freq[i+25][j]-freq[i-1][j]);
        break;
      }
      if(freq[i+25][j]-freq[i-1][j] == 0){
        need.pb(j);
        //printf("need %c\n",j+'A');
      }
    }
    if(flag) continue;
    if(need.size() <= freq[i+25][29]){
      //printf("i=%d\n",i);
      int k = 0;
      for(int j = i; j+i <= str.size()+1; j++){
        if(str[j-1] == '?'){
          char c = 'A';
          if(k < need.size()) c = need[k++]+'A';
          str[j-1] = c;
          if(k >= need.size()) k = 0;
        }
      }
      for(int j = 0; j <= i; j++){
        if(str[j-1] == '?'){
          char c = 'A';
          if(k < need.size()) c = need[k++]+'A';
          str[j-1] = c;
          if(k >= need.size()) k = 0;
        }
      }
      cout << str << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
