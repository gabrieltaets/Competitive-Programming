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

ll pd[2010][2010];
int n, k;

int main(){
	scanf("%d %d",&n,&k);
	for(int i = 1; i <= n; i++) pd[1][i] = 1;
	for(int len = 2; len <= k; len++){
		for(int i = 1; i <= n; i++){
			ll x = 0;
			for(int j = i; j <= n; j += i){
				x += pd[len-1][j];
				if(x >= 1000000007) x %= 1000000007;
			}
			pd[len][i] = x;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += pd[k][i];
		if(ans >= 1000000007) ans %= 1000000007;
	}
	printf("%lld\n",ans);
	return 0;
}
