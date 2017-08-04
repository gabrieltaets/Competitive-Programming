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

int n;
char grid[105][105];



int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%s",grid[i]);
	}
	for(int i = 0; i < n; i++){
		int cont = 0;
		for(int j = 0; j < n; j++){
			if(grid[i][j] == 'E' && grid[j][i] == 'E') cont++;
		}
		if(cont == n) {
			printf("-1\n");
			return 0;
		}
	}
	vii ans1, ans2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[i][j] == '.'){
				ans1.pb(mp(i+1,j+1));
				break;
			}
		}
		for(int j = 0; j < n; j++){
			if(grid[j][i] == '.'){
				ans2.pb(mp(j+1,i+1));
				break;
			}
		}
	}
	if(ans1.size() == n){
		for(int i = 0; i < ans1.size(); i++) printf("%d %d\n",ans1[i].F,ans1[i].S);
	}
	else if(ans2.size() == n){
		for(int i = 0; i < ans2.size(); i++) printf("%d %d\n",ans2[i].F,ans2[i].S);
	}
	else printf("-1\n");
	return 0;
}
