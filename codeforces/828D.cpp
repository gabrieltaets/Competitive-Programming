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
vector<int> graph[200010];

ii bfs(int source, bool show){
	int dist[200010];
	memset(dist, -1, sizeof dist);
	queue<int> q;
	q.push(source);
	ii maxdist(-1, -1);
	dist[source] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 0; i < graph[x].size(); i++){
			int u = graph[x][i];
			if(dist[u] == -1){
				if(show){
					printf("%d %d\n",x,u);
				}
				dist[u] = dist[x]+1;
				if(dist[u] >= maxdist.F){
					maxdist = mp(dist[u], u);
				}
				q.push(u);
			}
		}
	}
	return maxdist;
}

int main(){
	scanf("%d %d",&n,&m);
	queue<int> q;
	for(int i = 0; i < m; i++){
		graph[1].pb(i+2);
		graph[i+2].pb(1);
		q.push(i+2);
	}
	n -= m+1;
	int x = m+2;
	while(n--){
		int y = q.front();
		q.pop();
		graph[y].pb(x);
		graph[x].pb(y);
		q.push(x);
		x++;
	}
	x = bfs(1,0).S;
	printf("%d\n",bfs(x,0).F);
	bfs(1,1);
	return 0;
}
