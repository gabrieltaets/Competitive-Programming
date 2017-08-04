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

#define MOD 1000000007
ll pd[100010];

int main(){
	int t, k;
	scanf("%d %d",&t,&k);
	for(int i = 0; i < k; i++) pd[i] = 1;
	for(int i = k; i <= 100000; i++) pd[i] = (pd[i - k] + pd[i - 1])%MOD;
	pd[0] = 0;
	for(int i = 1; i <= 100000; i++){
		pd[i] = (pd[i] + pd[i-1])%MOD;
	}
	while(t--){
		int a, b;
		scanf("%d %d",&a,&b);
		ll ans = pd[b] - pd[a-1];
		while(ans < 0) ans += MOD;
		printf("%lld\n",ans);
	}
	return 0;
}

/*
660369142

xxxxxx
xxxx00 xxxxx1
xx0000 xxx100 xxx001 xxxx11
000000 x10000 x00100 xx1100 x00001 xx1001 xx0011 xxx111
110000 100100 001100 x11100 100001 001001 x11001 000011 x10011 x00111 xx1111
111100 111001 110011 100111 001111 111111

*/