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

bitset<20000000> bs;
vi prime;
vii twin;

void crivo(int ub){
	prime.pb(2);
	for(ll i = 3; i < ub; i += 2){
		if(bs[i]) continue;
		ll j;
		for(j = i * i; j < ub; j += i){
			bs[j] = 1;
		}
		if(*prime.rbegin() == i - 2){
			twin.pb(mp(*prime.rbegin(), i));
		}
		prime.pb(i);
	}
}

int main(){
	crivo(20000000);
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("(%d, %d)\n",twin[n-1].F,twin[n-1].S);
	}
	return 0;
}
