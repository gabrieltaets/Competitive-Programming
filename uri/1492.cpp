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

ll solve(int pos, bool menor, ll val){
  printf("At (%d,%s)\n",pos,menor?"menor":"maior");
  if(!val) return 0;
  if(pos == 0 && menor) return 2;
  if(pos == 0) return 1+(val&1);
  if(menor){
    ll ans = solve(pos-1,menor,val);
    printf("(%d,%s) received %lld\n",pos,menor?"menor":"maior",ans);
    return 2*ans;
  }
  ll ans1 = solve(pos-1,menor,val), ans2 = ((val&(1LL<<pos))?solve(pos-1,!menor,val):0);
  printf("(%d,%s) received %lld and %lld\n",pos,menor?"menor":"maior",ans1,ans2);
  return ans1 + ans2;
}

int main(){
  ll a, b;
  while(cin >> a){
    cout << solve(63,false,a) << endl;
  }
  return 0;
}
