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

int a[1010];
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
			a[i] += a[i-1];
		}
		int ans = INF;
		for(int i = 1; i <= n; i++){
			int esq = a[i-1];
			int dir = a[n] - esq;
			ans = min(ans,abs(esq-dir));
		}
		printf("%d\n",ans);
	}
	return 0;
}
