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

int n, r[100010];

bool okay(ll k){
	for(int i = 1; i <= n; i++){
		ll jump = r[i] - r[i-1];
		if(jump > k) return false;
		if(jump == k) k--;
	}
	return true;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int caso = 1; caso <= t; caso++){
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) scanf("%d",&r[i]);
		ll lo = 0, hi = 100000000000000LL, ans;
		while(lo <= hi){
			ll mid = (lo+hi)/2;
			if(okay(mid)){
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		printf("Case %d: %lld\n",caso,ans);
	}

	return 0;
}
