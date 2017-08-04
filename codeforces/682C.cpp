#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vii tree[100010];
vi nmbr;
int n, cont;

void dfs(int node, ll sum){
  if(sum < 0) sum = 0;
  for(int i = 0; i < tree[node].size(); i++){
    if(sum+tree[node][i].S <= nmbr[tree[node][i].F]){
      cont++;
      dfs(tree[node][i].F,sum+tree[node][i].S);
    }
  }
}

int main(){
  scanf("%d",&n);
  nmbr.pb(0);
  cont = 1;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    nmbr.pb(x);
  }
  for(int i = 2; i <= n; i++){
    int p, c;
    scanf("%d %d",&p,&c);
    tree[p].pb(ii(i,c));
  }
  dfs(1,0);
  cout << n-cont << endl;
  return 0;
}
