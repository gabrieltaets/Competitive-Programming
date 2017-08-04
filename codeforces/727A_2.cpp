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

vi ans;
bool dfs(int a, int b){
  if(a > b) return false;
  if(a == b){
    ans.pb(b);
    return true;
  }
  bool d2 = dfs(a*2,b), d10p1 = dfs(a*10+1,b);
  if(d2 || d10p1){
    ans.pb(a);
  }
  return d2 || d10p1;
}

int main(){
  int a, b;
  cin >> a >> b;
  bool res = dfs(a,b);
  if(res){
    cout << "YES\n";
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
      cout << ans[ans.size()-i-1] << " ";
    }
    cout << endl;
  }
  else cout << "NO\n";
	return 0;
}
