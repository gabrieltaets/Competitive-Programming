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

int N, M;
char grid[25][25], l;
int vis[25][25];
vi size;

int ff(int x, int y, int c){
	if(y == M) y = 0;
	if(y == -1) y = M-1;
	if(x < 0 || x >= N || grid[x][y] != l || vis[x][y]) return 0;
	vis[x][y] = c;
	int size = 1;
	size += ff(x+1, y, c);
	size += ff(x-1, y, c);
	size += ff(x, y+1, c);
	size += ff(x, y-1, c);
	return size;
}

int main(){
	while(scanf("%d %d",&N,&M) == 2){
		size.clear();
		size.pb(0);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				scanf(" %c",&grid[i][j]);
			}
		}
		memset(vis, 0, sizeof vis);
		int x, y, ans = 0, c = 2;
		scanf("%d %d",&x,&y);
		l = grid[x][y];
		ff(x,y,1);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(grid[i][j] != l || vis[i][j]) continue;
				ans = max(ans, ff(i,j,c++));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
