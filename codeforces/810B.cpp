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

typedef struct st {
	int p;
	int c;
	bool operator< (const struct st &x) const {
		ll g1 = min(p,c), g2 = min(2LL*p,(ll)c);
		ll h1 = min(x.p,x.c), h2 = min(2LL*x.p,(ll)x.c);
		return g2-g1<h2-h1;
	}
} DAY;

int main(){
	int n, f;
	scanf("%d %d",&n,&f);
	vector<DAY> v(n);
	for(int i = 0; i < n; i++){
		scanf("%d %d",&v[i].p,&v[i].c);
	}
	sort(v.begin(), v.end());
	ll s = 0;
	for(int i = v.size()-1; i >= 0; i--){
		if(f) {
			f--;
			s += min(2LL*v[i].p, (ll) v[i].c);
		}
		else  s += min(v[i].p, v[i].c);
	}
	printf("%lld\n",s);
	return 0;
}
