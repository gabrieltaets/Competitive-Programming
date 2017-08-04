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

#define MAXN 215

int dist[MAXN], n, e;
int busy[MAXN];
vector < pair <int,int> > edges;
int graph[MAXN][MAXN];
bool neg[MAXN];

void floyd_warshall(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}
}

bool bellman_ford(int s){
	int qtdArestas = edges.size();
	for(int i = 0; i < n; i++) dist[i] = INF;
	memset(neg,0,sizeof neg);
	dist[s] = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < qtdArestas; j++){
			int u = edges[j].first, v = edges[j].second;
			if(dist[u] < INF && dist[v] > dist[u] + graph[u][v])
				dist[v] = dist[u] + graph[u][v];
		} 
	}
	for(int i = 0; i < qtdArestas; i++){
		int u = edges[i].first, v = edges[i].second;
		if(dist[u] < INF && dist[v] > dist[u] + graph[u][v]) neg[v] = neg[u] = true;
	}
	return true;
} 



int main(){
	int caso = 1;
	while(scanf("%d",&n) == 1){
		edges.clear();
		memset(graph, INF, sizeof graph);
		memset(dist,INF,sizeof dist);
		for(int i = 0; i < n; i++){
			scanf("%d",&busy[i]);
			graph[i][i] = 0;
		}
		scanf("%d",&e);
		for(int i = 0; i < e; i++){
			int a, b;
			scanf("%d %d",&a,&b);
			a--; b--;
			graph[a][b] = (int) pow(busy[b]-busy[a],3.0);
			edges.pb(mp(a,b));
		}
		int q;
		scanf("%d",&q);
		bool ans = bellman_ford(0);
		//floyd_warshall();
		printf("Set #%d\n",caso++);
		while(q--){
			int x;
			scanf("%d",&x);
			x--;
			//dist[x] = graph[0][x];
			if(dist[x] < 3 || dist[x] >= 8000*200 || neg[x]) printf("?\n");
			else printf("%d\n",dist[x]);
		}
	}
	return 0;
}
