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

int n1, n2, k1, k2;
ll pd[101][101][11][11];
bool memo[101][101][11][11];

ll solve(int x1, int x2, int y1, int y2){
	if(y1 > k1 || y2 > k2) return 0;
	if(!x1 && !x2) return 1;
	if(memo[x1][x2][y1][y2]) return pd[x1][x2][y1][y2];
	memo[x1][x2][y1][y2] = 1;
	ll ans;
	if(!x1){
		ans = (y2 + x2 <= k2);
	}
	else if(!x2){
		ans = (y1 + x1 <= k1);
	}
	else {
		ans = solve(x1 - 1, x2, y1 + 1, 0) + solve(x1, x2 - 1, 0, y2 + 1);
	}
	return pd[x1][x2][y1][y2] = ans%100000000;
}

int main(){
	scanf("%d %d %d %d",&n1,&n2,&k1,&k2);
	printf("%lld\n",solve(n1,n2,0,0));
	return 0;
}
