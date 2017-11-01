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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll PA(ll x, ll y){
	return (x * (x+1) / 2) * (y * (y+1)/ 2);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll n, m, k;
		scanf("%lld %lld %lld",&n,&m,&k);
		ll total = PA(m, n);
		ll d = 0;
		ll erro = 0;
		ii b[k];
		for(int i = 0; i < k; i++){
			d=0;
			ll x, y;
			scanf("%lld %lld",&x,&y);
			b[i] = mp(x,y);
			d += PA(x-1, m);
			d += PA(n-x, m);
			d += PA(n, y-1);
			d += PA(n, m-y);
			d -= PA(x-1, y-1);
			d -= PA(x-1, n-y);
			d -= PA(n-x, y-1);
			d -= PA(n-x, n-y);
			erro += (total - d);
		}
		for(int i = 0; i < k; i++){
			for(int j = i + 1; j < k; j++){
				d = (1LL + llabs(b[i].F - b[j].F)) * (1LL + llabs(b[i].S - b[j].S));
				d = (n*m)-d;
				erro -= d;
			}
		}
		if(k > 1) erro += 4;
		printf("%lld\n",total - erro);
	}

	return 0;
}
