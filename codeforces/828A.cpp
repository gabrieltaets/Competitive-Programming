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
	ll n, a, b, c = 0, x, d = 0;
	scanf("%lld %lld %lld",&n,&a,&b);
	for(int i = 0; i < n; i++){
		scanf("%lld",&x);
		if(x == 1){
			if(a) a--;
			else if(b) {
				b--; c++;
			}
			else if(c) c--;
			else d++;
		}
		else {
			if(b) b--;
			else d += 2;
		}
	}
	printf("%lld\n",d);
	return 0;
}
