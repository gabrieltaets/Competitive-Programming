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

int n, e;
vi graph[210];

bool bfs(){
	int color[210];
	memset(color, -1, sizeof color);
	color[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(int i = 0; i < graph[a].size(); i++){
			int b = graph[a][i];
			if(color[b] == color[a]) {
				return false;
			}
			if(color[b] == -1){
				color[b] = (color[a] ^ 1);
				q.push(b);
			}
		}
	}
	return true;
}

int main(){
	while(scanf("%d",&n) == 1 && n){
		for(int i = 0; i < n; i++){
			graph[i].clear();
		}
		scanf("%d",&e);
		for(int i = 0; i < e; i++){
			int a, b;
			scanf("%d %d",&a,&b);
			graph[a].pb(b);
			graph[b].pb(a);
		}
		printf("%sBICOLORABLE.\n",bfs()?"":"NOT ");
	}
	return 0;
}
