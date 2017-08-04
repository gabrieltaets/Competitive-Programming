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
	int n, k;
	while(scanf("%d %d",&n,&k) && (n |k)){
		int a[1010];
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,greater<int>());
		printf("%d\n",a[k-1]);
	}
	return 0;
}
