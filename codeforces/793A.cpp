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
	scanf("%d %d",&n,&k);
	ll a[n], m = LINF, s = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld",&a[i]);
		m = min(m,a[i]);
	}
	for(int i = 0; i < n && s != -1; i++){
		ll c = (a[i]-m)/k;
		if(c*k+m == a[i]) s += c;
		else s = -1;
	}
	cout << s << endl;
	return 0;
}
