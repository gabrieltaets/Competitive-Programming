#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pf push_front
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int N, V[10010];
int solve(){
  deque<int> dq;
  sort(V,V+N);
  dq.pb(V[N-1]);
  int i = N-2, dif = 0;
  while(i>=0){
    dq.pb(V[i--]);
    if(i < 0) break;
    dq.pf(V[i--]);
  }
  for(i = 0; i < dq.size()-1; i++){
    dif = max(dif, abs(dq[i]-dq[i+1]));
  }
  dif = max(dif,abs(dq[0]-dq[N-1]));
  return dif;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    scanf("%d",&N);
    for(int i = 0; i < N; i++) scanf("%d",&V[i]);
    printf("%d\n",solve());
  }
  return 0;
}
