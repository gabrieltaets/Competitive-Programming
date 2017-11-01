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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, pd[2010][2010], s[2010];
bool memo[2010][2010];

ll solve(int p, int l){
	if(p == n+1) return 1;
	if(memo[p][l]) return pd[p][l];
	memo[p][l] = 1;
	int arr = s[p];
	int nxt = s[p+1];
	if((l < arr && nxt < l) || (l > arr && nxt > l)) return pd[p][l] = solve(p+1, arr);
	if((l < arr && nxt > arr) || (l > arr && nxt < arr)) return pd[p][l] = solve(p+1, l);
	return pd[p][l] = (solve(p+1, s[p]) + solve(p+1, l)) % ((1LLU << 31)-1);
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i <= n; i++){
		scanf("%d",&s[i]);
	}
	printf("%lld\n",solve(1, s[0]));
	return 0;
}
