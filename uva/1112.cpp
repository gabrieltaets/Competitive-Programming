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

int n, s, e, t;
vii graph[110];

int dijkstra(){
	int dist[110];
	memset(dist, INF, sizeof dist);
	priority_queue< ii, vii, greater<ii> > pq;
	pq.push({0,s});
	dist[s] = 0;
	while(!pq.empty()){
		int u = pq.top().S, d = pq.top().F;
		pq.pop();
		if(d > dist[u]) continue;
		
		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i].F, c = graph[u][i].S;
			if(dist[u] + c < dist[v]){
				dist[v] = dist[u] + c;
				pq.push({dist[v],v});
			}
		}
	}
	int cont = 0;
	for(int i = 1; i <= n; i++){
		if(dist[i] <= t) cont++;
	}
	return cont;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&s,&t);
		scanf("%d",&e);
		for(int i = 0; i <= n; i++) graph[i].clear();
		for(int i = 0; i < e; i++){
			int a, b, cost;
			scanf("%d %d %d",&a,&b,&cost);
			graph[b].pb({a, cost});
		}
		printf("%d\n",dijkstra());
		if(T) putchar('\n');
	}
	return 0;
}
