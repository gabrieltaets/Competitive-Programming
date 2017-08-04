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
	int a, b, c, d, ans = INF;
	cin >> a >> b >> c >> d;
	for(int i = 1; i <= sqrt(c); i++){
		if(c % i == 0){
			if((i % a == 0) && (i % b) && (d % i)) ans = min(ans, i);
			int inv = c / i;
			if((inv % a == 0) && (inv % b) && (d % inv)) ans = min(ans, inv);
		}
	}
	printf("%d\n",ans == INF ? -1 : ans);
	return 0;
}
