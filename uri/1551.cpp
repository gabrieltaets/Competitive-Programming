#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  getchar();
  while(n--){
    string str;
    getline(cin,str);
    set<char> s;
    for(int i = 0; i < str.size(); i++){
      if(isalpha(str[i])) s.insert(str[i]);
    }
    if(s.size() == 26) printf("frase completa\n");
    else if(s.size() >= 13) printf("frase quase completa\n");
    else printf("frase mal elaborada\n");
  }
  return 0;
}