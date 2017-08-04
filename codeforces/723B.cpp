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
  int n;
  char str[300];
  scanf("%d",&n);
  scanf(" %[^\n]",str);
  bool inPar = false, inWord = false;
  int numWord = 0, maxLen = 0, len = 0;
  for(int i = 0; i < n; i++){
    if(str[i] == '_'){
      if(!inPar) maxLen = max(len,maxLen);
      if(inWord && inPar) numWord++;
      len = 0;
      inWord = false;      
    }
    else if(str[i] == '('){
      inPar = true;
      maxLen = max(len,maxLen);
      len = 0;
    }
    else if(str[i] == ')'){
      inPar = false;
      if(inWord) numWord++;
      inWord = false;
    }
    else {
      if(inPar) inWord = true;
      else {
        len++;
        maxLen = max(len,maxLen);
      }
    }
  }
  cout << maxLen << " " << numWord << endl;
  return 0;
}
