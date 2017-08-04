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

int R, C, M, N;
int odd, even;
int grid[110][110];
int vis[110][110];

bool check(ii p){
	if(p.F < 0 || p.F >= R || p.S < 0 || p.S >= C || !grid[p.F][p.S]) return false;
	return true;
}

void show(){
	printf("\n");
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(vis[i][j]) putchar('O');
			else printf("%c",grid[i][j]?'.':'X');
		}
		printf("\n");
	}
	printf("\n");
}

void bfs(){
	ii off[] = { {M, N}, {N, M}, {M, -N}, {N, -M}, {-M, N}, {-N, M}, {-M, -N}, {-N, -M} };
	memset(vis, 0, sizeof vis);
	queue<ii> q;
	q.push({0,0});
	vis[0][0] = 1;
	odd = even = 0;
	while(!q.empty()){
		ii p(q.front()); q.pop();
		int cont = 0;
		set<ii> dif;
		for(int i = 0; i < 8; i++){
			ii nxt(p.F+off[i].F,p.S+off[i].S);
			if(check(nxt)){
				if(dif.insert(nxt).S) cont++;
				if(!vis[nxt.F][nxt.S]) {
					vis[nxt.F][nxt.S] = 1;
					q.push(nxt);
				}
			}
		}
		if(cont&1) odd++;
		else even++;
	}
}


int main(){
	int T;
	scanf("%d",&T);
	for(int caso = 1; caso <= T; caso++){
		scanf("%d %d %d %d",&R,&C,&M,&N);
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				grid[i][j] = 1;
		int w;
		scanf("%d",&w);
		for(int i = 0; i < w; i++){
			int a, b;
			scanf("%d %d",&a,&b);
			grid[a][b] = 0;
		}
		bfs();
		printf("Case %d: %d %d\n",caso,even,odd);
	}
	return 0;
}
