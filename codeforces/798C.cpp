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

inline ll gcd(ll a, ll b){
  return b ? gcd(b, a%b) : llabs(a);
}

int main(){
	int n, cont = 0;;
	scanf("%d",&n);
	ll a[100010];
	ll g;
	for(int i = 0; i < n; i++){
		scanf("%lld",&a[i]);
		if(i) g = gcd(g,a[i]);
		else g = a[i];
	}
	if(g > 1){
		return !printf("YES\n0\n");
	}
	for(int i = 0; i < n - 1; i++){
		while(a[i]&1){
			pair<ll,ll> x(a[i],a[i+1]);
			a[i] = x.F-x.S;
			a[i+1] = x.F+x.S;
			cont++;
		}
	}
	while(a[n-1]&1){
		pair<ll,ll> x(a[n-2],a[n-1]);
		a[n-2] = x.F-x.S;
		a[n-1] = x.F+x.S;
		cont++;
	}
	g = llabs(a[0]);
	for(int i = 1; i < n; i++){
		g = gcd(g,llabs(a[i]));
	}
	if(g > 1) printf("YES\n%d\n",cont);
	else printf("NO\n");
	return 0;
}
