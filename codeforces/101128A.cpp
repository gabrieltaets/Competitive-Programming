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

vi graph[5010], graphr[5010];
int a, b, n, m;
int sub[5010], abv[5010], vis[5010][2];

void dfs(int no, int chk){
	vis[no][0] = 1;
	sub[chk]++;
	for(int i = 0; i < graph[no].size(); i++){
		int x = graph[no][i];
		if(vis[x][0]) continue;
		dfs(x, chk);
	}
}

void dfsr(int no, int chk){
	vis[no][1] = 1;
	abv[chk]++;
	for(int i = 0; i < graphr[no].size(); i++){
		int x = graphr[no][i];
		if(vis[x][1]) continue;
		dfsr(x, chk);
	}
}

int main(){
	scanf("%d %d %d %d",&a,&b,&n,&m);
	for(int i =0 ; i < m; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		graph[x].pb(y);
		graphr[y].pb(x);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) vis[j][0] = vis[j][1] = 0;
		dfs(i, i);
		dfsr(i, i);
	}
	int ga = 0, gb = 0, imp = 0;
	for(int i = 0; i < n; i++){
		if(a > n - sub[i]) ga++;
		if(b > n - sub[i]) gb++;
		if(b < abv[i]) imp++;
	}
	printf("%d\n%d\n%d\n",ga,gb,imp);
	return 0;
}
