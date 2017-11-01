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

ll n, m, k;

ll count(ll x){
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		sum += min((x-1)/i, (ll)m);
	}
	return sum;
}

int main(){
	scanf("%lld %lld %lld",&n,&m,&k);
	ll lo = 0, hi = n*m, ans = 0;
	while(lo <= hi){
		ll mid = (lo+hi)/2;
		if(count(mid) < k){
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	printf("%lld\n",ans);
	return 0;
}
