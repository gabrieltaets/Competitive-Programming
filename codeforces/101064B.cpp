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

int n;
int pd[100][2];
int solve(int p, bool m){
  if(n == 1 || n == 2) return n;
  if(p==n) return 1+!m;
  if(pd[p][m] != -1) return pd[p][m];
  ll ans = 0;
  if(m){
    ans = solve(p+1,!m)%1000000007;
  }
  else ans = (solve(p+1,m)*solve(p+1,!m)+1)%1000000007;
  return pd[p][m] = ans;
}

int main(){
  scanf("%d",&n);
  memset(pd,-1,sizeof pd);
  cout << solve(1,0) << endl;
  return 0;
}
