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

int graph[110][110];

int n;
set<int> seen;

void floyd_warshall(){
	for(int k = 1; k < 110; k++){
		for(int i = 1; i < 110; i++){
			for(int j = 1; j < 110; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main(){
	int a, b, caso = 1;
	while(scanf("%d %d",&a,&b) == 2 && (a || b)){
		seen.clear();
		memset(graph,INF,sizeof graph);
		seen.insert(a);
		seen.insert(b);
		for(int i = 0; i < 110; i++) graph[i][i] = 0;
		graph[a][b] = 1;
		while(scanf("%d %d",&a,&b) && (a || b)){
			seen.insert(a);
			seen.insert(b);
			graph[a][b] = 1;
		}
		int sum = 0;
		floyd_warshall();
		for(int i = 1; i < 110; i++){
			if(seen.count(i) == 0) continue;
			for(int j = 1; j < 110; j++){
				if(seen.count(j) == 0) continue;
				sum += graph[i][j];
			}
		}
		n = seen.size();
		printf("Case %d: average length between pages = %.3lf clicks\n",caso++,(double)sum/(n*n-n));
	}
	
	return 0;
}
