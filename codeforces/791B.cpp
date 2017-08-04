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
vi graph[150035];
vi grau[150035];
int vis[150035];

void dfs(int no, int pai, int cc){
	vis[no] = cc;
	grau[cc].pb(graph[no].size());
	for(int i = 0; i < graph[no].size(); i++){
		int x = graph[no][i];
		if(x == pai || vis[x]) continue;
		dfs(x, no, cc);
	}
}

int main(){
	int cc = 1;
	memset(vis, 0, sizeof vis);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i, -1, cc);
			cc++;
		}
	}
	for(int i = 1; i < cc; i++){
		int g = grau[i][0];
		for(int j = 1; j < grau[i].size(); j++){
			if(grau[i][j] != grau[i].size()-1){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}
