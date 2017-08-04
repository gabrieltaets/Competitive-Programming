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

ll a, b, cont;
map<ll,ll> m;
ll par[100010];

bool dfs(ll val, ll p){
  if(m[val] == 0) m[val] = cont++;
  par[m[val]] = p;
  if(val == b) {
    return true;
  }
  bool ans = false;
  if(val*2 <= b){
    ans = dfs(val*2,val);
    if(ans) return ans;
  }
  if(val*10+1LL <= b)
    ans = dfs(val*10+1LL,val);
  return ans;
}

void show(){
  stack<ll> st;
  cout << "YES\n";
  for(ll i = b; i != a; i = par[m[i]]){
    st.push(i);
  }
  st.push(a);
  cout << st.size() << endl;
  while(!st.empty()){
    printf("%lld ",st.top());
    st.pop();
  }
}

void solve(){
  m[a] = 1;
  m[b] = 2;
  cont = 3;
  par[m[a]] = -1;
  if(dfs(a,par[m[a]])) show();
  else cout << "NO\n";
}

int main(){
  cin >> a >> b;
  solve();
  return 0;
}
