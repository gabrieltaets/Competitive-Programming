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
vi graph[110];
stack<int> ans;
int vis[110];

void dfs(int node){
	vis[node] = 1;
	for(int i = 0; i < graph[node].size(); i++){
		int x = graph[node][i];
		if(vis[x]) continue;
		dfs(x);
	}
	ans.push(node);
}

int main(){
	while(scanf("%d %d",&n,&m) == 2 && (n || m)){
		for(int i = 0; i <= n; i++) graph[i].clear();
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < m; i++){
			int a, b;
			scanf("%d %d",&a,&b);
			graph[a].pb(b);
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]) dfs(i);
		}
		if(!ans.empty()) {
			printf("%d",ans.top());
			ans.pop();
		}
		while(!ans.empty()){
			printf(" %d",ans.top());
			ans.pop();
		}
		printf("\n");
	}
	return 0;
}
