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

int n, m;
vi graph[100010];
set<int> Q[100010];
int c[100010];
ii ans(0, INF);
void bfs(){
	int vis[n+100];
	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int a = q.front(); q.pop();
		for(int i = 0; i < graph[a].size(); i++){
			int x = graph[a][i];
			if(!vis[x]) q.push(x);
			vis[x] = 1;
			if(c[a] != c[x]) {
				Q[c[a]].insert(c[x]);
				Q[c[x]].insert(c[a]);
				if(Q[c[a]].size() > ans.F){
					ans.F = Q[c[a]].size();
					ans.S = c[a];
				}
				if(Q[c[x]].size() > ans.F){
					ans.F = Q[c[x]].size();
					ans.S = min(ans.S, c[x]);
				}
				if(Q[c[a]].size() == ans.F) ans.S = min(ans.S, c[a]);
				if(Q[c[x]].size() == ans.F) ans.S = min(ans.S, c[x]);
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&c[i]);
		ans.S = min(ans.S, c[i]);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		if(c[a] == c[b]) continue;
		Q[c[a]].insert(c[b]);
		Q[c[b]].insert(c[a]);
		if(Q[c[a]].size() > ans.F){
			ans.F = Q[c[a]].size();
			ans.S = c[a];
		}
		if(Q[c[b]].size() > ans.F){
			ans.F = Q[c[b]].size();
			ans.S = c[b];
		}
		if(Q[c[a]].size() == ans.F) ans.S = min(ans.S, c[a]);
		if(Q[c[b]].size() == ans.F) ans.S = min(ans.S, c[b]);
	}
	printf("%d\n",ans.S);
	return 0;
}
