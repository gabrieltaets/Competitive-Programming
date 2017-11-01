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

ll a, b, N;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld",&a,&b,&N);
		ll cont[10], ans[10];
		memset(ans,0,sizeof ans);
		char str[10];
		for(int i = 1; i <= N; i++){
			ll x = a*i*i + b*i;
			if(x > N) break;
			ll mc = 0;
			memset(cont, 0, sizeof cont);
			sprintf(str,"%lld",x);
			for(int j = 0; str[j]; j++){
				cont[str[j]-'0']++;
				mc = max(mc, cont[str[j]-'0']);
			}
			for(int j = 0; j < 10; j++){
				if(cont[j] == mc) ans[j]++;
			}
		}
		pair<ll,ll> p(0, -1);
		for(int i = 0; i < 10; i++){
			if(ans[i] > p.F) p = mp(ans[i], i);
		}
		printf("%lld\n",p.S);
	}
	return 0;
}
