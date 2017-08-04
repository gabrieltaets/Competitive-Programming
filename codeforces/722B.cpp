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

bool isVowel(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main(){
  int n;
  scanf("%d",&n);
  int p[n];
  for(int i = 0; i < n; i++){
    scanf("%d",&p[i]);
  }
  char str[110], *pChar;
  for(int i = 0; i < n; i++){
    int syl = 0;
    scanf(" %[^\n]",str);
    for(int j = 0; str[j]; j++){
      if(isVowel(str[j])) syl++;
    }
    if(syl != p[i]){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
