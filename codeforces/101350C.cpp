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

ll v[100100];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		ll s = 0;
		for(int i = 0; i < n; i++){
			scanf("%lld",&v[i]);
			s += v[i];
		}
		ll g = v[0];
		for(int i = 1; i < n; i++){
			g = __gcd(g, v[i]);
		}
		printf("%lld %lld\n",s,g);
	}
	return 0;
}
