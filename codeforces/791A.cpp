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
	ll a, b, c = 0;
	cin >> a >> b;
	while(a <= b){
		a *= 3;
		b *= 2;
		c++;
	}
	cout << c << endl;
	return 0;
}
