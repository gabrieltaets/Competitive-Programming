#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
ll x[300010];

ll fexp(ll x, int p){
	if(p == 0) return 1;
	ll ans = fexp(x,(p>>1));
	ans *= ans;
	if(ans >= (ll)(1e9+7)) ans %= (ll)(1e9+7);
	if(p&1){
		ans *= x;
		if(ans >= (ll)(1e9+7)) ans %= (ll)(1e9+7);
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%lld",&x[i]);
	}
	sort(x,x+n);
	ll s = 0;
	for(int i = 0; i < n; i++){
		ll f = fexp(2LL,i)-fexp(2LL,n-i-1);
		while(f<0) f += (ll)(1e9+7);
		s += f*x[i];
		if(s > (ll)(1e9+7)) s %= (ll)(1e9+7);
	}
	printf("%lld\n",s);

	return 0;
}
