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

int main(){
	int n, m;
	char grid[110][110];
	scanf("%d %d",&n,&m);
	getchar();
	bool flag = false;
	ii a(INF,INF), b(-1, -1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			grid[i][j] = getchar();
			if(grid[i][j] == 'B'){
				a.F = min(a.F, i);
				a.S = min(a.S, j);
				b.F = max(b.F, i);
				b.S = max(b.S, j);
				flag = true;
			}
		}
		getchar();
	}
	if(!flag){
		printf("1\n");
		return 0;
	}
	ii sz(b.F-a.F+1, b.S-a.S+1);
	sz.F = max(sz.F, sz.S);
	sz.S = max(sz.F, sz.S);
	if(sz.F > n || sz.F > m){
		printf("-1\n");
		return 0;
	}
	int cont = 0;
	for(int i = a.F; i <= b.F; i++){
		for(int j = a.S; j <= b.S; j++){
			if(grid[i][j] == 'W') cont++;
		}
	}
	cont += sz.F * sz.S - (b.F-a.F+1)*(1+b.S-a.S);
	printf("%d\n",cont);
	return 0;
}
