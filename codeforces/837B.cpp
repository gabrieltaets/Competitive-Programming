/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

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

char grid[110][110];
int n, m;

bool checkHor(int q){
	set<char> seen;
	char at = grid[0][0];
	seen.insert(at);
	for(int i = 0; i < q; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] != at) return false;
		}
	}
	at = grid[q][0];
	seen.insert(at);
	for(int i = q; i < 2*q; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] != at) return false;
		}
	}
	at = grid[2*q][0];
	seen.insert(at);
	for(int i = 2*q; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] != at) return false;
		}
	}
	return seen.count('R') && seen.count('G') && seen.count('B');
}

bool checkVer(int q){
	set<char> seen;
	char at = grid[0][0];
	seen.insert(at);
	for(int i = 0; i < q; i++){
		for(int j = 0; j < n; j++){
			if(grid[j][i] != at) return false;
		}
	}
	at = grid[0][q];
	seen.insert(at);
	for(int i = q; i < 2*q; i++){
		for(int j = 0; j < n; j++){
			if(grid[j][i] != at) return false;
		}
	}
	at = grid[0][2*q];
	seen.insert(at);
	for(int i = 2*q; i < m; i++){
		for(int j = 0; j < n; j++){
			if(grid[j][i] != at) return false;
		}
	}
	return seen.count('R') && seen.count('G') && seen.count('B');
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%s",grid[i]);
	bool ans = false;
	if(n%3==0) ans |= checkHor(n/3);
	if(m%3==0) ans |= checkVer(m/3);
	printf("%s\n",ans?"YES":"NO");
	return 0;
}
