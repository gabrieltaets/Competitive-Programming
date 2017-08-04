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

char grid[15][15];
int vis[15][15];
int ans;
ii check[] = { ii(1, 1), ii(1, -1), ii(-1, 1), ii(-1, -1) };
ii mov[] = { ii (2, 2), ii(2, -2), ii(-2, 2), ii(-2, -2) };
ii src;

void dfs(ii pos, int d){
	//printf("At (%d, %d) [%d]\n",pos.F,pos.S,d);
	ans = max(ans, d);
	for(int i = 0; i < 4; i++){
		ii x(pos.F+check[i].F, pos.S+check[i].S);
		ii dest(pos.F+mov[i].F, pos.S+mov[i].S);
		if(grid[x.F][x.S] == 'B' && vis[x.F][x.S] != 1 && (dest == src || grid[dest.F][dest.S] == '#')){
			vis[x.F][x.S] = 1;
			//printf("Jumping from (%d, %d) to (%d, %d)\n", pos.F, pos.S, dest.F, dest.S);
			dfs(dest, d+1);
			//printf("setting vis[%d][%d] (%d) to 2\n",x.F,x.S,vis[x.F][x.S]);
			vis[x.F][x.S] = 2;
			//printf("vis[%d][%d] = %d\n",x.F,x.S,vis[x.F][x.S]);
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		vii start;
		for(int i = 0; i < 15; i++) for(int j = 0; j < 15; j++) grid[i][j] = '.';
		for(int i = 1; i <= 10; i++){
			for(int j = 1; j <= 10; j++){
				scanf(" %c",&grid[i][j]);
				if(grid[i][j] == 'W') start.pb(mp(i,j));
			}
		}
		ans = 0;
		for(int i = 0; i < start.size(); i++){
			memset(vis,0,sizeof vis);
			src = start[i];
			dfs(start[i], 0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
