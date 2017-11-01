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

ll T, N, D;
ll A[100010];

int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld %lld",&N,&D);
		ll s = 0;
		for(int i = 0; i < N; i++){
			scanf("%lld",&A[i]);
			s += A[i];
		}
		if(s % N){
			printf("-1\n");
			continue;
		}
		ll x = s / N;
		ll qtd = 0;
		for(int i = 0; i < N; i++){
			ll q = x - A[i];
			if(i + D < N){
				A[i] += q;
				A[i+D] -= q;
				qtd += abs(q);
			}
			if(A[i] != x) {
				qtd = -1;
				break;
			}
		}
		printf("%lld\n",qtd);
	}
	return 0;
}
