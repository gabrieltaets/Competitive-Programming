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

ii dir[] = { ii(0,1), ii(0,-1), ii(1, 0), ii(-1, 0), ii(1, 1), ii(1, -1), ii(-1, 1), ii(-1, -1) };
char grid[15][15];

bool check(int i, int j, int k, int q, bool flag){
	//printf("checking %d %d %d %d %d\n",i,j,k,q,flag);
	if(q == 0) return true;
	if(i < 1 || i > 10 || j < 1 || j > 10 || grid[i][j] == 'O') return false;
	if(grid[i][j] == '.' && !flag) return false;
	return check(i+dir[k].F, j+dir[k].S, k, q-1, flag & grid[i][j] == 'X');
}

int main(){
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			grid[i][j] = getchar();
		}
		getchar();
	}
	bool ans = false;
	for(int i = 1; i <= 10 && !ans; i++){
		for(int j = 1; j <= 10 && !ans; j++){
			if(grid[i][j] == 'X'){
				for(int k = 0; k < 8 && !ans; k++) {
					ans = check(i, j, k, 5, true);
					//if(ans) printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	printf("%s\n",ans?"YES":"NO");
	return 0;
}
