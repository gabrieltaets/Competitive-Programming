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

int grafo[25][25], custo[25];
int dist[25], best, n;

void fw(){
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				grafo[i][j] = min(grafo[i][j], grafo[i][k] + grafo[k][j]);
}

void dfs(int no, int prof, int cost){
	int menor = INF, midx = -1;
	if(cost <= 420 && prof > best) best = prof;
	dist[no] = prof;
	for(int i = 0; i < n; i++){
		if(!dist[i] && grafo[no][i] < menor){
			menor = grafo[no][i];
			midx = i;
		}
	}
	if(midx != -1){
		dfs(midx, prof+1, cost + grafo[no][midx] + custo[midx]);
	}
}

void solve(){
	best = 0;
	for(int i = 0; i < n; i++){
		memset(dist,0,sizeof dist);
		dfs(i, 1, custo[i]);
	}
}

int main(){
	while(scanf("%d",&n) && n){
		for(int i = 0; i < n; i++) scanf("%d",&custo[i]);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d",&grafo[i][j]);
			}
		}
		fw();
		solve();
		printf("%d\n",best);
	}
	return 0;
}
