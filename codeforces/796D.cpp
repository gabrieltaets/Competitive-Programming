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

int n, k, d;
vi p;
vi graph[300010];
int vis[300010];
map<ii,int> road;
set<int> ans;

void bfs(){
	memset(vis,-1,sizeof vis);
	queue<ii> q;
	for(int i = 0; i < k; i++){
		vis[p[i]] = 0;
		q.push({p[i],-1});
	}
	while(!q.empty()){
		int a = q.front().F, pai = q.front().S; q.pop();
		if(vis[a] == d) continue;
		for(int i = 0; i < graph[a].size(); i++){
			int v = graph[a][i];
			if(v == pai) continue;
			if(vis[v] == -1) {
				vis[v] = vis[a]+1;
				q.push({v,a});
				ans.erase(road[{a,v}]);
			}
		}
	}
	
}

int main(){
	scanf("%d %d %d",&n,&k,&d);
	for(int i = 0; i < k; i++){
		int x;
		scanf("%d",&x);
		p.pb(x);
	}
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		graph[u].pb(v);
		graph[v].pb(u);
		road[{u,v}] = i;
		road[{v,u}] = i;
		ans.insert(i);
	}
	bfs();
	printf("%d\n",ans.size());
	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
		printf("%d ",*it);
	}
	printf("\n");
	return 0;
}
