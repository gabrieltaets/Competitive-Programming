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
ll pd[2005][2005];

ll solve(int l, int s){
  if(l == 0 && s == 0) return 1;
  if(l == 0) return s+1;
  if(pd[l][s] != -1) return pd[l][s];
  pd[l][s] = 1;
  if(l) pd[l][s] = (pd[l][s] + solve(l-1,s+1))%9999959999LL;
  if(s) pd[l][s] = (pd[l][s] + solve(l,s-1))%9999959999LL;
  return pd[l][s];
}

int main(){
  int l, s;
  memset(pd,-1,sizeof pd);
  while(scanf("%d %d",&l,&s) && (s || l)){
    cout << solve(l,s) << endl;
  }
  return 0;
}
