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
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], x = INF;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] && a[i] <= k) x = min(x,10*abs(m-i));
	}
	printf("%d\n",x);
	return 0;
}
