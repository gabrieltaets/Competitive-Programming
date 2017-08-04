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
	ll k, a, b, qa, qb;
	cin >> k >> a >> b;
	if(k > a && k > b){
		printf("-1\n");
		return 0;
	}
	qa = a/k;
	qb = b/k;
	a -= qa*k;
	b -= qb*k;
	if(a > qb*(k-1) || b > qa*(k-1)){
		printf("-1\n");
		return 0;
	}
	cout << (qa+qb) << endl;
	return 0;
}
