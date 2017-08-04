#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LINF 0x3f3f3f3f3f3f3f3f
#define HI 10000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii AdjList[110];
int V, E, K;
struct no {
  int node;
  ll comb, refuels;
  no (int a=-1, ll b = 0, ll c = LINF){
    node = a;
    comb = b;
    refuels = c;
  }
  bool operator< (const no x) const {
    if(refuels == x.refuels) return comb > x.comb;
    return refuels < x.refuels;
  }
  bool operator> (const no x) const {
    return x < *this;
  }
};

ll recharges, shuttle;

int dijkstra(int s){
  pair<ll,ll> res[V];
  for(int i = 0; i < V; i++) {
    res[i] = mp(LINF,0);
  }
  res[s] = mp(1,shuttle);
  bool reached[V];
  memset(reached,false,sizeof reached);
  int n = s;
  while(!reached[n]){
    reached[n] = true;
    printf("Checking V = %d\n",n);
    for(int i = 0; i < AdjList[n].size(); i++){
      ii d = AdjList[n][i];
      if(reached[d.F]) continue;
      if(shuttle < d.S) continue;
      if(res[d.F].F == res[n].F){
        if(res[n].S - d.S > res[d.F].S){
          res[d.F].S = res[n].S - d.S;
        }
      }
      else if(res[d.F].F == 1 + res[n].F){
        if(shuttle-d.S > res[d.F].S){
          res[d.F].S = shuttle-d.S;
        }
      }
      else if(res[d.F].F > res[n].F){
        res[d.F].S = shuttle-d.S;
        res[d.F].F = res[n].F+1;
      }
    }
    no menor, temp;
    for(int i = 0; i < V; i++){
      if(reached[i]) continue;
      temp = no(i,res[i].S,res[i].F);
      printf("%d %lld %lld\n",temp.node,temp.comb,temp.refuels);
      if(temp < menor) {
        menor = temp;
      }
    }
    n = menor.node;
    if(n == -1) break;
  }
  recharges = 0;
  for(int i = 0; i < V; i++){
    recharges = max(recharges,res[i].F);
  }
  return recharges;
}

bool check(ll s){
  recharges = 0;
  shuttle = s;
  bool ans = true;
  for(int i = 0; i < V; i++){
    recharges = 0;
    printf("(%lld) Checking path for V=%d:\n",s,i);
    if(dijkstra(i) > K) ans = false;
    getchar();
    printf("(%lld) Completed %d with %lld recharges\n",s,i,recharges);
  }
  return ans;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    for(int i = 0; i < 110; i++) AdjList[i].clear();
    scanf("%d %d %d",&V,&K,&E);
    for(int i = 0; i < E; i++){
      int a, b, w;
      scanf("%d %d %d",&a,&b,&w);
      AdjList[a].pb(mp(b,w));
      AdjList[b].pb(mp(a,w));
    }
    getchar();
    ll lo = 1, hi = HI, mid, ans;
    while(lo <= hi){
      ll mid = (lo+hi)/2;
      if(check(mid)){
        ans = mid;
        hi = mid-1;
      }
      else {
        lo = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
