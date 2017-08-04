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

ll fexp(ll e){
	if(!e) return 1LL;
	ll ans = fexp(e/2LL);
	ans = (ans * ans)%((1LL<<31)-1);
	if(e&1LL) ans = (ans * 3)%((1LL<<31)-1);
	return ans;
}

int main(){
	ll n;
	cin >> n;
	cout << fexp(n) << endl;
	return 0;
}
