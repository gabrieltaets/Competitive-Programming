#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-6
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll b1, q, l, m;
	bool hasZero = false;
	bool hasInit = false;
	bool hasNegInit = false;
	cin >> b1 >> q >> l >> m;
	ll a[m];
	for(int i = 0; i < m; i++) {
		cin >> a[i];
		if(!a[i]) hasZero = true;
		if(a[i] == b1) hasInit = true;
		if(a[i] == -b1) hasNegInit = true;
	}
	if(abs(b1) > l){
		printf("0\n");
		return 0;
	}
	if(b1 == 0){
		if(hasZero){
			printf("0\n");
			return 0;
		}
		printf("inf\n");
		return 0;
	}
	if(q == 0){
		if(hasZero && (hasInit || abs(b1) > l)){
			printf("0\n");
			return 0;
		}
		if(hasZero){
			printf("1\n");
			return 0;
		}
		printf("inf\n");
		return 0;
	}
	if(q == 1){
		if(hasInit || abs(b1) > l){
			printf("0\n");
			return 0;
		}
		printf("inf\n");
		return 0;
	}
	if(q == -1){
		if((hasInit && hasNegInit) || abs(b1) > l){
			printf("0\n");
			return 0;
		}
		printf("inf\n");
		return 0;
	}
	ll qtd = (ll) floor(log((double)l/abs(b1))/log(abs(q))) + 1LL;
	ll cont = 0;
	//printf("Expected %lld terms\n",qtd);
	for(int i = 0; i < m; i++){
		if(abs(a[i]) > l) continue;
		ll x = log((double) abs(a[i]) / abs(b1))/log(abs(q));
		//cout << x << endl;
		if(x >= 0 && x <= qtd-1 && pow(q,x)*b1 == a[i]) {
			//printf("%d shall not appear\n",a[i]);
			cont++;
		}
	}
	printf("%lld\n",qtd-cont);
	
	return 0;
}
