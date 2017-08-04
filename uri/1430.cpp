#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  string str;
  map<char,int> v;
  v['W'] = 64;
  v['H'] = 32;
  v['Q'] = 16;
  v['E'] = 8;
  v['S'] = 4;
  v['T'] = 2;
  v['X'] = 1;
  while(cin >> str && str[0] != '*'){
    int s = 0;
    int q = 0;
    for(int i = 0; i < str.size(); i++){
      if(str[i] == '/') {
        if(s == 64){
          q++;
        }
        s = 0;          
      }
      else {
        s += v[str[i]];
      }
    }
    printf("%d\n",q);
  }
  return 0;
}