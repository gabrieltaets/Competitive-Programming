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
  int n; string str, ans;
  cin >> n >> str;
  for(int i = 0; i < n; i++){
    if((str.size()-i)&1){
      ans.pb(str[i]);
    }
    else {
      ans = str.substr(i,1) + ans;
    }
  }
  cout << ans << endl;
	return 0;
}
