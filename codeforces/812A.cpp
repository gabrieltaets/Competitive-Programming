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

int g[5][5];

int main(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			scanf("%d",&g[i][j]);
		}
	}
	bool ans = false;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			int c = (i-j-1+4)%4;
			if((g[i][j] && g[i][3]) || (g[i][j] && g[c][3])) ans = true;
		}
	}
	printf("%s\n",ans?"YES":"NO");
	return 0;
}
