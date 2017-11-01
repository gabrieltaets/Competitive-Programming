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

int s[100010];
ll acc[100010];

ll solve(int l, int r){
	if(l >= r) return 0;
	pair<ll,int> best(LINF, 0);
	for(int i = l; i < r; i++){
		ll dif = llabs((acc[r] - acc[i]) - (acc[i] - acc[l-1]));
		if(dif < best.F){
			best = mp(dif, i);
		}
	}
	return solve(l, best.S) + solve(best.S+1, r) + acc[r] - acc[l-1];
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
			scanf("%d",&s[i]);
		sort(s+1,s+n+1);
		for(int i = 1; i <= n; i++) acc[i] = acc[i-1]+s[i];
		printf("%lld\n",solve(1, n));
	}
	return 0;
}
