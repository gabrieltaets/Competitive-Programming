#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ll N, V[1000010];
ll solve(){
  priority_queue<ii> pq;
  for(ll i = 0; i < N; i++){
    pq.push(ii(V[i],-i));
  }
  ll pos = 0;
  ll profit = 0;
  while(!pq.empty()){
    ll val = pq.top().F, p = -pq.top().S;
    ll q = 0;
    pq.pop();
    if(pos >= p) continue;
    printf("Next sell: %d (%d)\n",val,p);
    while(pos < p) {
      profit -= V[pos++];
      q++;
    }
    profit += q * V[p];
    pos++;
    if(profit < 0) profit = 0;
  }
  return profit;
}
int main(){
  ll T;
  scanf("%lld",&T);
  while(T--){
    scanf("%lld",&N);
    for(ll i = 0; i < N; i++) scanf("%lld",&V[i]);
    printf("%lld\n",solve());
  }
  return 0;
}
