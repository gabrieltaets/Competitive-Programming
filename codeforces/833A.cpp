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

int main(){
	int n;
	unordered_map<ll,ll> cb;
	for(ll i = 1; i <= 1000000; i++){
		cb.insert({i*i*i,i});
	}
	scanf("%d",&n);
	while(n--){
		ll a, b;
		scanf("%lld %lld",&a,&b);
		ll x = cb[a*b];
		printf("%s\n",x!=0&&a%x==0&&b%x==0?"Yes":"No");
	}
	return 0;
}
