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
int n;
int k[4], num[4];
map<int,char> mapa;
string getstr(){
  string ans;
  for(int i = 1; i <= 27; i++){
    for(int j = 1; j <= 27; j++){
      for(int y = 1; y <= 27; y++){
        int x = y + 100*j + 10000*i;
        int z;
        for(z = 0; z < 4; z++){
          if(x%k[z] != num[z]) break;
        }
        if(z == 4){
          ans.pb(mapa[i]);
          ans.pb(mapa[j]);
          ans.pb(mapa[y]);
        }
      }
    }
  }
  return ans;
}

string decode(string str){
  for(int i = 0; i < 8; i+=2){
    num[i/2] = (str[i]-'0')*10 + (str[i+1]-'0');
  }
  return getstr();
}
int main(){
  mapa[27] = ' ';
  for(int i = 1; i < 27; i++){
    mapa[i] = 'A'+i-1;
  }
  cin >> n;
  while(n--){
    int g;
    cin >> g;
    string ans, str;
    for(int i = 0; i < 4; i++) cin >> k[i];
    for(int i = 0; i < g; i++){
      cin >> str;
      if(str.size() == 7) str = "0" + str;
      str = decode(str);
      ans += str;
    }
    for(int i = ans.size()-1; i >= 0; i--){
      if(ans[i] != ' ') {
        ans = ans.substr(0,i+1);
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
