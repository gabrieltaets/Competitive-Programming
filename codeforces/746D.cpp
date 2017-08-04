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

ll n, k, a, b;

int solve(int c, int t, int q){
  
}

int main(){
  int qta = 0, qtb = 0;
  string ans;
  cin >> n >> k >> a >> b;
  if(a > b){
    int q = ceil((double)a/k)-1;
    if(b < q){
      printf("NO\n");
      return 0;
    }
    qta += k;
    ans = string(k,'G');
    while(qta != a){
      ans.pb('B');
      qtb++;
      ans += string(min(k,a-qta),'G');
      qta += min(k,a-qta);
    }
    for(int i = 1; i < ans.size(); i++){
      if(ans[i] == 'G' && ans[i-1] == 'B'){
        ans.insert(i,min(k-1,b-qtb),'B');
        qtb += min(k-1,b-qtb);
        i += min(k-1,b-qtb);
      }
    }
    if(qtb != b){
      ans += string(b-qtb,'B');
    }
  }
  else {
    int q = ceil((double)b/k)-1;
    if(a < q){
      printf("NO\n");
      return 0;
    }
    qtb += k;
    ans = string(k,'B');
    while(qtb != b){
      ans.pb('G');
      qta++;
      ans += string(min(k,b-qtb),'B');
      qtb += min(k,b-qtb);
    }
    for(int i = 1; i < ans.size(); i++){
      if(ans[i] == 'B' && ans[i-1] == 'G'){
        ans.insert(i,min(k-1,a-qta),'G');
        qta += min(k-1,a-qta);
        i += min(k-1,a-qta);
      }
    }
    if(qta != a){
      ans += string(a-qta,'G');
    }
  }
  cout << ans << endl;
	return 0;
}
