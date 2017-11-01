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

int tr[30][400010];
int left[100010];
int right[100010];
int sh[100010];
vi graph[100010];
int n, m;
int d[100010];
int pos[100010];
vi v[30];

int dfs(int node, int dep){
	d[node] = dep;
	v[dep].pb(sh[node]);
	p[node] = v[dep].size()-1;
	if(graph[node].size() >= 1)
		left[node] = dfs(graph[node][0], dep+1);
	if(graph[node].size() >= 2)
		right[node] = dfs(graph[node][1], dep+1);
	return p[node];
}

void build(int dep, int no, int l, int r){
	if(l == r) {
		tr[dep][no] = v[dep][r];
		return;
	}
	build(dep+1, left[no])
}

int main(){
	scanf("%d %d %d",&n,&m,&sh[1]);
	for(int i = 1; i < n; i++){
		int u, v, w;
		scanf("%d %d %d",&u,&v,&w);
		graph[v].pb(u);
		sh[u] = w;
	}
	return 0;
}
