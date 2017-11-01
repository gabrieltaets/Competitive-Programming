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

int mat[30][30];
int pd[10010][30];
bool memo[10010][30];
int k;

int solve(int len, int at){
	if(len == k-1) return 0;
	if(memo[len][at]) return pd[len][at];
	memo[len][at] = 1;
	pd[len][at] = INF;
	for(int i = 0; i < 26; i++){
		pd[len][at] = min(pd[len][at], solve(len+1,i)+mat[at][i]);
	}
	return pd[len][at];
}

int main(){
	memset(pd,INF,sizeof pd);
	scanf("%d",&k);
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	int ans = INF;
	for(int i = 0; i < 26; i++){
		ans = min(ans, solve(0,i));
	}
	printf("%d\n",ans);
	return 0;
}
