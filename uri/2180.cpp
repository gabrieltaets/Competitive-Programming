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

vi primos;
bitset<10000000> bs;

void crivo(){
	primos.pb(2);
	for(ll i = 3; i < 10000000; i+=2){
		if(bs[i]) continue;
		for(ll j = i * i; j < 10000000; j += i){
			bs[j] = 1;
		}
		primos.pb(i);
	}
}

int main(){
	crivo();
	int p, s = 0;
	scanf("%d",&p);
	vi::iterator it = lower_bound(primos.begin(), primos.end(), p);
	for(int i = 0; i < 10; i++){
		s += *it;
		it++;
	}
	printf("%d km/h\n%d h / %d d\n", s, 60000000 / s, 60000000 / s / 24);
	return 0;
}
