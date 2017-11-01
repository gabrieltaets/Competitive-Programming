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

int n, k;
pair<ll,ll> num[210];
pair<ll,ll> pd[210][210];
bool memo[210][210];

ll solve(int x, int u){
	printf("at %d %d %lld %lld\n",x,u,q2,q5);
	if(x == n) return mp(0LL, 0LL);
	if(memo[x][u]) return pd[x][u];
	memo[x][u] = 1;
	ll ans1 = solve(x+1, u, q2, q5);
	ll ans2 = solve(x+1, u-1, q2+num[x].F, q5+num[x].S);
	return pd[x][u] = max(ans1, ans2);
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; i++){
		ll x;
		num[i] = mp(0,0);
		scanf("%d",&x);
		while(x % 2 == 0){
			x >>= 1;
			num[i].F++;
		}
		while(x % 5 == 0){
			x /= 5;
			num[i].S++;
		}
	}
	printf("%lld\n",solve(0,k));
	return 0;
}
