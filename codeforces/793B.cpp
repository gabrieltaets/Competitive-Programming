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

typedef struct stnode {
	int i, j, d, t;
	stnode(int a, int b, int c, int e){
		i = a; j = b; d = c; t = e;
	}
	bool operator< (const struct stnode &x) const {
		if(i != x.i) return i < x.i;
		if(j != x.j) return j < x.j;
		if(d != x.d) return d < x.d;
		if(t != x.t) return t < x.t;
		return false;
	}
} node;

char grid[1010][1010];
int m, n;
int vis[1010][1010][5][3];
queue<node> q;
ii s, t;
ii dir[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

node next(node x){
	node y = x;
	y.i += dir[x.d].F;
	y.j += dir[x.d].S;
	return y;
}

bool valid(node x){
	if(x.i < 0 || x.i >= n || x.j < 0 || x.j >= m || grid[x.i][x.j] == '*' || x.t == -1) return false;
	return true;
}

bool visited(node x){
	return vis[x.i][x.j][x.d][x.t];
}

void visit(node x){
	vis[x.i][x.j][x.d][x.t] = 1;
}


bool solve(){
	memset(vis,0,sizeof vis);
	for(int i = 0 ; i < 4; i++){
		node x = node(s.F,s.S,i,2);
		q.push(x);
		visit(x);
	}
	while(!q.empty()){
		node x = q.front(); q.pop();
		node y = next(x);
		//printf("Now at [%d][%d][%d][%d]\n",x.i,x.j,x.d,x.t);
		if(valid(y) && !visited(y)){
			q.push(y);
			visit(y);
		}
		for(int i = 0; i < 4; i++){
			if(x.d == i) continue;
			node z = x;
			z.d = i;
			z = next(z);
			z.t--;
			if(valid(z) && !visited(z)){
				q.push(z);
				visit(z);
			}
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			node x(t.F,t.S,i,j);
			if(visited(x)) return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c",&grid[i][j]);
			if(grid[i][j] == 'S') s = {i,j};
			if(grid[i][j] == 'T') t = {i,j};
			if(grid[i][j] != '*') grid[i][j] = '.';
		}
	}
	printf("%s\n",solve()?"YES":"NO");
	
	return 0;
}
