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

int main(){
	ll n, l, r, cont = 0;
	cin >> n >> l >> r;
	if(n == 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<ll> fac;
	for(ll i = n; i; (i >>= 1)){
		fac.pb(i);
	}
	reverse(fac.begin(),fac.end());
	for(ll i = l; i <= r; i++){
		int e;
		for(e = 51; e >= 0; e--){
			if(i%(1LL<<e) == 0) break;
		}
		cont += (fac[e]&1);
	}
	cout << cont << endl;
	return 0;
}
