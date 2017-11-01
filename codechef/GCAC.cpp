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
	
int T, N, M, minSalary[1010], offeredSalary[1010], maxJobOfers[1010], qtdNull, qtdEmployed, hired[1010];
bool qual[1010][1010];
ll sum;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&M);
		for(int i = 0; i < N; i++) scanf("%d",&minSalary[i]);
		for(int i = 0; i < M; i++) {
			scanf("%d %d",&offeredSalary[i], &maxJobOfers[i]);
			hired[i] = 0;
		}
		getchar();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++){
				qual[i][j] = (getchar() == '1');
			}
			getchar();
		}
		qtdNull = M, sum = 0, qtdEmployed = 0;
		for(int i = 0; i < N; i++){
			pair<ll,ll> best(-1,-1);
			for(int j = 0; j < M; j++){
				if(qual[i][j] && hired[j] < maxJobOfers[j] && offeredSalary[j] >= minSalary[i] && offeredSalary[j] > best.F){
					best = mp(offeredSalary[j], j);
				}
			}
			int cmp = best.S;
			if(cmp != -1){
				if(!hired[cmp]) qtdNull--;
				hired[cmp]++;
				sum += best.F;
				qtdEmployed++;
			}
		}
		printf("%d %lld %d\n",qtdEmployed,sum,qtdNull);
	}
	return 0;
}
