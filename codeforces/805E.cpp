#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, m;
vector<int> graph[300010];
int color[300010];

int main(){
	scanf("%d %d",&n,&m);
	int maxcor = 0, ans = 0;
	set<int> colors;
	for(int i = 1; i <= m; i++) colors.insert(i);
	for(int i = 0; i < n; i++){
		set<int> used;
		int cor = 1;
		int s;
		scanf("%d",&s);
		for(int j = 0; j < s; j++){
			int c;
			scanf("%d",&c);
			graph[i].pb(c);
			if(!color[c]){
				color[c] = cor++;
				maxcor = max(maxcor,cor);
			}
			colors.erase(color[c]);
		}
		for(int j = 0; j < s; j++){
			int c = graph[i][j];
			if(!used.count(color[c])){
				used.insert(color[c]);
			}
			else {
				color[c] = *(colors.begin());
				used.insert(color[c]);
			}
			printf("color[%d] = %d\n",c,color[c]);
			ans = max(ans,color[c]);
		}
		for(int j = 0; j < s; j++){
			int c = graph[i][j];
			colors.insert(color[c]);
		}
	}
	printf("%d\n",ans);
	for(int i = 1; i <= m; i++){
		printf("%d ",color[i]);
	}
	printf("\n");
	
	return 0;
}
