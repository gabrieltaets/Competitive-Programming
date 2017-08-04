#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LOGN 60
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int q;
struct edge {
  ll a, b, c;
  edge(ll x, ll y, ll z){
    a = x; b = y; c = z;
  }
};
vector<edge> cost;

ll D(ll x){
  return (ll)log2(x);
}

ll LCA(ll A, ll B){
	ll x, y, dif;
	dif = abs(D(B)-D(A));
	if(D(B) < D(A)) swap(A,B);
	y = A, x = B;
	if(D(A) < D(B)){
    x >>= dif;
	}
	if(x == y) return x;
	for(int i = LOGN; i >= 0; i--){
		if((x >> i) != (y >> i)){
			x >>= i;
			y >>= i;
		}
	}
	return (x >> 1);
}

ll check(ll a, ll b){
  if(b > a) swap(a,b);
  ll sum = 0, L1, L2;
  for(int i = 0; i < cost.size(); i++){
    L1 = LCA(a, cost[i].b), L2 = LCA(cost[i].a,a);
    printf("[L1(%lld,%lld)=%lld] ",a,cost[i].b,L1);
    if(L1 == cost[i].b){
      printf("From %lld to %lld: %lld (%lld edges)",b,a,(ll)log2((double)a/b)*cost[i].c,(ll)log2((double)a/b));
      sum += (ll)log2((double)a/cost[i].b)*cost[i].c;
      sum -= (ll)log2((double)cost[i].a/a)*cost[i].c;
    }
    printf("\n");
  }
  return sum;
}

int main(){
  scanf("%d",&q);
  for(int i = 0; i < q; i++){
    int o;
    ll a, b, c, L;
    scanf("%d %lld %lld",&o,&a,&b);
    L = LCA(a,b);
    printf("Paths: (%lld,%lld) and (%lld,%lld)\n",a,L,b,L);
    if(o == 1) {
      scanf("%lld",&c);
      if(a != L) cost.pb(edge(a,L,c));
      if(b != L) cost.pb(edge(b,L,c));
    }
    else {
      ll sum = 0;
      if(a != L) sum += check(a,L);
      if(b != L) sum += check(b,L);
      cout << sum << endl;
    }
  }
  return 0;
}
