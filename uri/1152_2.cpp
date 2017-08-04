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

#define MAXN 200035

int vis[MAXN];
priority_queue<ii> pq;
vii AdjList[MAXN];

void processar(int v){
	vis[v] = 1;
	for(int j = 0; j < AdjList[v].size(); j++){
		ii u = AdjList[v][j];
		if(!vis[u.first])
			pq.push(ii(-u.second, -u.first));
	} 
}

int prim(){
	int mst_cost = 0;
	memset(vis,0,sizeof vis);
	processar(0);
	while(!pq.empty()){
		ii front = pq.top();
		pq.pop();
		int u = -front.second, w = -front.first;
		if(!vis[u]){
			mst_cost += w;
			processar(u);
		}
	}
	return mst_cost;
} 

int main(){
	int M, N, X, Y, Z, i, maxc;
    scanf("%d %d",&M,&N);
    while(M || N){
		//for(int i = 0; i < N; i++) AdjList[i].clear();
		maxc = 0;
        for(i = 0; i < N; i++){
            scanf("%d %d %d",&X,&Y,&Z);
			AdjList[X].pb({Y,Z});
			AdjList[Y].pb({X,Z});
			maxc += Z;
        }
        printf("%d\n",maxc-prim());
        scanf("%d %d",&M,&N);
    }
	return 0;
}
