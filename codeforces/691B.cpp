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
  string str;
  cin >> str;
  map<char,char> mapa;
  mapa['A'] = 'A';
  mapa['H'] = 'H';
  mapa['I'] = 'I';
  mapa['M'] = 'M';
  mapa['O'] = 'O';
  mapa['T'] = 'T';
  mapa['U'] = 'U';
  mapa['V'] = 'V';
  mapa['W'] = 'W';
  mapa['X'] = 'X';
  mapa['Y'] = 'Y';
  mapa['b'] = 'd';
  mapa['d'] = 'b';
  mapa['o'] = 'o';
  mapa['v'] = 'v';
  mapa['w'] = 'w';
  mapa['x'] = 'x';
  mapa['p'] = 'q';
  mapa['q'] = 'p';
  for(int i = 'A'; i <= 'Z'; i++){
    mapa.insert(mp(i,(char)0));
  }
  for(int i = 'a'; i <= 'z'; i++){
    mapa.insert(mp(i,(char)0));
  }
  for(int i = 0; i <= str.size()/2; i++){
    if(mapa[str[i]] != str[str.size()-i-1] || mapa[str[str.size()-i-1]] != str[i]){
      cout << "NIE\n";
      return 0;
    }
  }
  cout << "TAK\n";
  return 0;
}