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

#define MAXN 100010
#define LOGN 20

int pai[MAXN][LOGN+1], N, Q;
vi V[MAXN];
int D[MAXN];
int dist[MAXN];

void dfs(int no, int p, int dep){
	D[no] = dep;
	pai[no][0] = p;
	for(int i = 1; i <= LOGN; i++){
		pai[no][i] = pai[pai[no][i-1]][i-1];
	}
	for(int i = 0; i < V[no].size(); i++){
		int k = V[no][i];
		if(k != p){
			dist[k] = dist[no] + 1;
			dfs(k,no,dep+1);
		}
	}
}

int LCA(int A, int B){
	int x, y, dif;
	dif = abs(D[B]-D[A]);
	if(D[B] < D[A]) swap(A,B);
	y = A, x = B;
	if(D[A] < D[B]){
		for(int i = LOGN; i >= 0; i--){
			if((1 << i) <= dif){
				x = pai[x][i];
				dif -= (1 << i);
			}
		}
	}
	if(x == y) return x;
	for(int i = LOGN; i >= 0; i--){
		if(pai[x][i] != pai[y][i]){
			x = pai[x][i];
			y = pai[y][i];
		}
	}
	return pai[x][0];
}

int Dist(int A, int B){
	if(A == B) return 0;
	return dist[A]+dist[B]-2*dist[LCA(A,B)];
}	

void init(){
	for(int i = 0; i <= N; i++) for(int j = 0; j <= LOGN; j++) pai[i][j] = 0;
	for(int i = 0; i <= N; i++) dist[i] = 0;
	D[0] = 0;
	for(int i = 0; i < V[0].size(); i++){
		dist[V[0][i]] = 1;
		dfs(V[0][i],0,1);
	}
}

int solve(int a, int b, int c){
	int L = LCA(b, c);
	return max(Dist(a, L), max(Dist(b, L), Dist(c, L)))+min();
}

int main(){
	int q;
	scanf("%d %d",&N,&q);
	for(int i = 1; i <= N-1; i++){
		int x;
		scanf("%d",&x);
		x--;
		V[i].pb(x);
		V[x].pb(i);
	}
	init();
	while(q--){
		int x[3];
		scanf("%d %d %d",x,x+1,x+2);
		x[0]--; x[1]--; x[2]--;
		
		printf("%d\n",best+1);
	}
	return 0;
}
