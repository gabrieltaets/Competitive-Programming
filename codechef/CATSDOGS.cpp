#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll T, C, D, L;
	cin >> T;
	while(T--){
		cin >> C >> D >> L;
		if(L%4){
			cout << "no\n";
			continue;
		}
		ll minc = max(0LL,(C - D*2)*4);
		if(L >= D*4+minc && L <= C*4+D*4) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}

  