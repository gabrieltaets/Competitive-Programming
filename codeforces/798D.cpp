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

pair<pair<ll,ll>,int> a[100010], b[100010], a2[100010], b2[100010];
int main(){
	int n;
	scanf("%d",&n);
	ll cumA = 0, cumB = 0;
	int	k = n/2+1;
	for(int i = 0; i < n; i++){
		scanf("%lld",&a[i].F.F);
		cumA += a[i].F.F;
		a[i].S = i+1;
		a2[i] = a[i];
	}
	for(int i = 0; i < n; i++){
		scanf("%lld",&b[i].F.F);
		cumB += b[i].F.F;
		b[i].S = i+1;
		b[i].F.S = a[i].F.F;
		a[i].F.S = b[i].F.F;
		b2[i] = b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	reverse(a,a+n);
	reverse(b,b+n);
	set<int> ans;
	int x = 0, y = 0;
	ll sumA = 0, sumB = 0;
	for(int i = 0; i < k/2*2; i++){
		if(!(i&1) || ((2LL*sumB > cumB) && (2LL*sumA <= cumA))){
			while(!ans.insert(a[x].S).S) x++;
			sumA += a[x].F.F;
			sumB += a[x].F.S;
		}
		else if((i&1) || ((2LL*sumA > cumA) && (2LL*sumB <= cumB))){
			while(!ans.insert(b[y].S).S) y++;
			sumB += b[y].F.F;
			sumA += b[y].F.S;
		}
		else {
			while(!ans.insert(a[x].S).S) x++;
			sumA += a[x].F.F;
			sumB += a[x].F.S;
		}
	}
	if(k&1){
		for(int i = 0; i < n; i++){
			if(ans.count(i+1)) continue;
			if(2LL*(sumA+a2[i].F.F) > cumA && 2LL*(sumB+b2[i].F.F) > cumB){
				ans.insert(i+1);
				break;
			}
		}
	}
	printf("%d\n",ans.size());
	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
		printf("%d ",*it);
	}
	printf("\n");
	return 0;
}
