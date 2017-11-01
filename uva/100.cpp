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

int solve(int x){
	if(x == 1) return 1;
	if(x & 1) return solve(3*x+1)+1;
	return solve(x/2)+1;
}

int main(){
	int a, b;
	while(scanf("%d %d",&a,&b)!=EOF){
		int ans = 0;
		for(int i = min(a,b); i <= max(a,b); i++){
			ans = max(ans, solve(i));
		}
		printf("%d %d %d\n",a,b,ans);
	}
	return 0;
}
