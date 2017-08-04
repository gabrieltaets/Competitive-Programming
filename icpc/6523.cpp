#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int n;
  cin >> n;
  string nomes[n];
  vector<string> words[n];
  char buffer[1100], *pChar, *pChar2;
  for(int i = 0; i < n; i++){
    cin >> nomes[i];
    gets(buffer);
    for(int j = 0; buffer[j]; j++)
      buffer[j] = tolower(buffer[j]);
    pChar = strtok(buffer," ");
    while(pChar != NULL){
      words[i].pb(string(pChar));
      pChar = strtok(NULL," ");
    }
  }
  gets(buffer);
  while(gets(buffer)!=NULL){
    for(int i = 0; buffer[i]; i++) buffer[i] = tolower(buffer[i]);
    pChar = strtok(buffer," ,.!;?()");
    while(pChar != NULL){
      int ans = -1;
      for(int i = 0; i < n && ans == -1; i++){
        for(int j = 0; j < words[i].size() && ans == -1; j++){
          if(strcmp(pChar,words[i][j].c_str()) == 0){
            ans = i;
          }
        }
      }
      if(ans != -1){
        cout << nomes[ans] << endl;
        break;
      }
      pChar = strtok(NULL," ,.!;?()");
    }
  }
  return 0;
}
