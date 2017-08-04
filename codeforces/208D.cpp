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

int n;
ll p[10], g[10], a[100];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%lld",&a[i]);
	for(int i = 0; i < 5; i++) scanf("%lld",&p[i]);
	ll x = 0;
	for(int i = 0; i < n; i++){
		x += a[i];
		for(int j = 4; j >= 0; j--){
			g[j] += x / p[j];
			x %= p[j];
		}
	}
	for(int i = 0 ; i < 5; i++) printf("%lld ",g[i]);
	printf("\n%lld\n",x);
	return 0;
}
