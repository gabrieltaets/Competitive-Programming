#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string s;
	cin >> s;
	ll cb = 0;
	ll qtd = 0;
	int i;
	for(i = s.size()-1; i >= 0; i--) 
		if(s[i] == 'b') break;
	for(; i >= 0; i--){
		if(s[i] == 'b'){
			cb++;
			continue;
		}
		qtd = (qtd+cb)%MOD;
		cb *= 2;
		cb %= MOD;
	}
	cout << qtd << endl;
	return 0;
}
