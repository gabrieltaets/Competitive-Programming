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
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  string ans;
  int qta = 0, qtb = 0;
  while(qta < a || qtb < b){
    ans += string(k,'G') + string(k,'B');
    qta += k;
    qtb += k;
  }
  int i = ans.size()-1;
  while(1){
    if(ans[i] == 'G' && qta > a){
      qta--;
      ans.pop_back();
      i--;
    }
    else if(ans[i] == 'B' && qtb > b){
      qtb--;
      ans.pop_back();
      i--;
    }
    else break;
  }
  while(qta > a || qtb > b){
    while(ans[i] == 'G' && qta > a){
      if(i && ans[i-1] == 'B') break;
      ans.erase(i,1);
      qta--;
      i--;
    }
    while(ans[i] == 'B' && qtb > b){
      if(i && ans[i-1] == 'G') break;
      ans.erase(i,1);
      qtb--;
      i--;
    }
    i--;
    if(i < 0) break;
  }
  int xa = 0, xb = 0;
  for(int i = 0; i < ans.size(); i++){
    if(ans[i] == 'G') xa++;
    else xb++;
  }
  if(xa > a || xb > b){
    cout << "NO\n";
    return 0;
  }
  cout << ans << endl;
	return 0;
}
