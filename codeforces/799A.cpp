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
	int n, t, k, d, q = 0, a1;
	cin >> n >> t >> k >> d;
	if(d >= (double)(ceil((double)n/k)-1)*t){
		printf("NO\n");
	}
	else printf("YES\n");
	return 0;
}
