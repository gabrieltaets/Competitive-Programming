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

int N, M, S, dir;
char grid[110][110];
ii off[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
ii pos;

int main(){
	while(scanf("%d %d %d",&N,&M,&S) == 3 && (N | M | S)){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				scanf(" %c",&grid[i][j]);
				if(grid[i][j] == 'N'){
					pos = {i, j};
					dir = 0;
				}
				if(grid[i][j] == 'S'){
					pos = {i, j};
					dir = 2;
				}
				if(grid[i][j] == 'L'){
					pos = {i, j};
					dir = 1;
				}
				if(grid[i][j] == 'O'){
					pos = {i, j};
					dir = 3;
				}
			}
		}
		grid[pos.F][pos.S] = '.';
		int cont = 0;
		for(int i = 0; i < S; i++){
			char c;
			scanf(" %c",&c);
			switch(c){
			  case 'D':
				dir = (dir+1)%4;
				break;
			  case 'E':
				dir = (dir-1 >= 0 ? dir - 1 : dir + 3);
				break;
			  case 'F':
				ii npos(pos.F + off[dir].F, pos.S + off[dir].S);
				if(npos.F < 0 || npos.F >= N || npos.S < 0 || npos.S >= M || grid[npos.F][npos.S] == '#') break;
				pos = npos;
				if(grid[pos.F][pos.S] == '*') cont++;
				grid[pos.F][pos.S] = '.';
				break;
			}
		}
		printf("%d\n",cont);		
	}
	
	return 0;
}
