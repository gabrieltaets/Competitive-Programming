/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

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

void show(ll x){
	string s;
	for(int i = 63; i >= 0; i--){
		s.pb('0'+(bool)(x&(1LL<<i)));
	}
	cout << s << endl;
}

int main(){
	ll l, r, a = 0, b = 0;
	cin >> l >> r;
	for(int i = 62; i >= 0; i--){
		if(a < l && (l & ~a) >= (1LL << i)) a |= (1LL << i);
		if(b < l && (l & ~b) >= (1LL << i) && (b | (1LL << i)) <= r) {
			b |= (1LL << i);
		}
		else if((b | (1LL << i)) <= r && !(a & (1LL << i))) {
			b |= (1LL << i);
		}
		if((a | (1LL << i)) <= r && !(b & (1LL << i))) a |= (1LL << i);
	}
	printf("%lld\n",a^b);
	return 0;
}
