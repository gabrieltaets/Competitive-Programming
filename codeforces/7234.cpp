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
int N, V[1000010];
ll solve(){
  priority_queue<ii> pq;
  for(int i = 0; i < N; i++){
    pq.push(ii(V[i],i));
  }
  int pos = 0;
  ll profit = 0;
  while(!pq.empty()){
    int val = pq.top().F, p = pq.top().S, q = 0;
    pq.pop();
    if(pos >= p) continue;
    while(pos < p) {
      profit -= V[pos++];
      q++;
    }
    profit += q * V[p];
    if(profit < 0) profit = 0;
  }
  return profit;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    for(int i = 0; i < N; i++) scanf("%d",&V[i]);
    printf("%lld\n",solve());
  }
  return 0;
}
