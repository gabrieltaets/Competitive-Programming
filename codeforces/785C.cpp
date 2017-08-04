#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MAXN 1000000000000000000LL
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll n, m;

bool empty(double day){
	double qtd = n - day*(1+day)/2 - m;
	return qtd <= 0;
}

int main(){
	cin >> n >> m;
	ll lo = 1, hi = n, ans = 0;
	if(m >= n){
		cout << n << endl;
		return 0;
	}
	while(lo <= hi){
		ll mid = (lo+hi)/2;
		if(empty(mid)){
			//printf("At day %d barn will be empty\n",mid+m);
			ans = mid;
			hi = mid-1;
		}
		else {
			//printf("At day %d barn will not be empty\n",mid+m);
			lo = mid+1;
		}
	}
	cout << ans+m << endl;
	return 0;
}