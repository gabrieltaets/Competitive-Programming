#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

ll power3(ll e){
  if(e == 0LL) return 1;
  ll ans = power3((e>>1))%1000000007;
  ans = (ans*ans)%1000000007;
  if(e&1LL) ans = (ans*3LL)%1000000007;
  return ans;
}

int main(){
  string str;
  cin >> str;
  map<char,string> mapa;
  for(int i = 0; i < (1<<6); i++){
    string x;
    for(int j = 5; j >= 0; j--){
      if(i&(1<<j)) x.push_back('1');
      else x.push_back('0');
    }
    if(i < 10){
      mapa['0'+i] = x;
    }
    else if(i < 36){
      mapa['A'+i-10] = x;
    }
    else if(i < 62){
      mapa['a'+i-36] = x;
    }
    else if(i == 62) mapa['-'] = x;
    else mapa['_'] = x;
  }
  string bitmask;
  for(int i = 0; i < str.size(); i++){
    bitmask += mapa[str[i]];
  }
  ll cnt0 = 0;
  for(int i = 0; i < bitmask.size(); i++){
    if(bitmask[i] == '0') cnt0++;
  }
  cout << power3(cnt0) << endl;
  return 0;
}