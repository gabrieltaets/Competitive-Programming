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
	int n, m, k, cont = 0;
	cin >> n >> m >> k;
	int army[m], fedor;
	for(int i = 0; i < m; i++) cin >> army[i];
	cin >> fedor;
	for(int i = 0; i < m; i++){
		int dif = __builtin_popcount(army[i] ^ fedor);
		if(dif <= k) cont++;
	}
	cout << cont << endl;
	return 0;
}
