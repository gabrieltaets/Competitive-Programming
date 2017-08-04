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
int day[110];
int pd[110][2];
int solve(int d, int a){
  if(d == n) return 0;
  if(pd[d][a] != -1) return pd[d][a];
  pd[d][a] = 0;
  if(a == 0 && (day[d] == 1 || day[d] == 0)) return pd[d][a] = 1 + min(solve(d+1,a),solve(d+1,a^1));
  if(a == 1 && (day[d] == 2 || day[d] == 0)) return pd[d][a] = 1 + min(solve(d+1,a),solve(d+1,a^1));
  return pd[d][a] = solve(d+1,a^1);
}
int main(){
  memset(pd,-1,sizeof pd);
  scanf("%d",&n);
  for(int i = 0; i < n; i++) scanf("%d",&day[i]);
  cout << min(solve(0,0),solve(0,1)) << endl;
  return 0;
}
