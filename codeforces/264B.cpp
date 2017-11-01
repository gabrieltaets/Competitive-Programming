/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, a[100010], v[100010], m, md[100010];
vi primos;
bitset<100010> bs;

void crivo(){
	for(ll i = 2; i <= 100000; i++){
		if(bs[i]) continue;
		for(ll j = i * i; j <= 100000; j += i){
			bs[j] = 1;
			md[j] = i;
		}
		primos.pb(i);
		md[i] = i;
	}
}

set<int> fact(int x){
	set<int> ans;
	while(x > 1){
		ans.insert(md[x]);
		x /= md[x];
	}
	return ans;
}

int main(){
	crivo();
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	for(int i = n-1; i >= 0; i--){
		set<int> f = fact(a[i]);
		int k = 0;
		for(set<int>::iterator it = f.begin(); it != f.end(); it++){
			k = max(k, v[*it]);
		}
		for(set<int>::iterator it = f.begin(); it != f.end(); it++){
			v[*it] = k + 1;
		}
		m = max(m, k+1);
	}
	printf("%d\n",m);
	return 0;
}
