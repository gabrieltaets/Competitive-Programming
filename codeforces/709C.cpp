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
  string s;
  cin >> s;
  bool started = false;
  for(int i = 0; i < s.size(); i++){
    if(s[i] > 'a'){
      s[i]--;
      started = true;
    }
    else if(started) break;
  }
  if(!started) s[s.size()-1] = 'z';
  cout << s << endl;
  return 0;
}
