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

int graph[40][40], mf, f, s, t, n;
vi p;
void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return;
	}
	else if(p[v] != -1){
		augment(p[v], min(minEdge,graph[p[v]][v]));
		graph[p[v]][v] -= f;
		graph[v][p[v]] += f;
	} 
}

int edmonds_karp(){
	mf = 0;
	while(1){
		f = 0;
		vi dist(n+1,INF);
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		p.assign(n+1,-1);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == t) break;
			for(int v = 0; v <= n; v++){
				if(graph[u][v] > 0 && dist[v] == INF){
					dist[v] = dist[u] + 1;
					q.push(v); p[v] = u;
				} 
			} 
		}
		augment(t,INF);
		if(f == 0) break;
		mf += f;
	}
	return mf;
}

int main(){
	int N, M, T;
	cin >> T;
	map<string,int> mapa;
	mapa["XXL"] = 1;
	mapa["XL"] = 2;
	mapa["L"] = 3;
	mapa["M"] = 4;
	mapa["S"] = 5;
	mapa["XS"] = 6;
	while(T--){
		cin >> N >> M;
		n = M + 8;
		s = 0; t = M + 7;
		memset(graph,0,sizeof graph);
		for(int i = 1; i < 7; i++){
			graph[0][i] = N/6;
		}
		for(int i = 7; i < t; i++){
			graph[i][t] = 1;
			graph[t][i] = 1;
		}
		for(int i = 0; i < M; i++){
			string t1, t2;
			cin >> t1 >> t2;
			graph[mapa[t1]][i+7] = 1;
			graph[mapa[t2]][i+7] = 1;
		}
		if(edmonds_karp() == M) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
