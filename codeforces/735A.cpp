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
  int n, k, g, t;
  cin >> n >> k;
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == 'G') g = i;
    if(str[i] == 'T') t = i;
  }
  if(g > t){
    while(g > t) {
      g -= k;
      if(g < 0 || str[g] == '#') break;
    }
  }
  else {
    while(g < t) {
      g += k;
      if(g >= str.size() || str[g] == '#') break;
    }
  }
  if(g == t) cout << "YES\n";
  else cout << "NO\n";
	return 0;
}
