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

vector<ll> largest;

int main(){
	ll n, k;
	cin >> n >> k;
	int cont = 0;
	for(ll i = 1LL; i <= sqrt(n); i++){
		if(n%i == 0){
			cont++;
			if(n/i != i) largest.pb(n/i);
		}
		if(cont == k){
			cout << i << endl;
			return 0;
		}
	}
	if(k-cont > largest.size()){
		cout << -1 << endl;
		return 0;
	}
	cout << largest[largest.size()-k+cont] << endl;
	return 0;
}
