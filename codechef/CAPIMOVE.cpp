#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int T, N;
ii P[50035];
vi graph[50035];
int ans[50035];

int main(){
	scanf("%d",&T);
	while(T--){
		memset(ans,-1,sizeof ans);
		scanf("%d",&N);
		for(int i = 0; i < N; i++){
			scanf("%d",&P[i].F);
			P[i].S = i;
		}
		sort(P,P+N);
		for(int i = 1; i < N; i++){
			int U, V;
			scanf("%d %d",&U,&V);
			U--; V--;
			graph[U].pb(V);
			graph[V].pb(U);
		}
		int solved = 0;
		for(int i = N-1; i >= 0; i--){
			int sel = P[i].S;
			for(int j = 0; j < N; j++){
				if(sel == j) continue;
				if(ans[j] == -1){
					//printf("%d is answer to %d\n",sel+1,1+j);
					ans[j] = sel;
					solved++;
				}
			}
			for(int j = 0; j < graph[sel].size(); j++){
				int c = graph[sel][j];
				if(ans[c] == sel){
					//printf("%d is no longer answer to %d\n",sel+1,c+1);
					ans[c] = -1;
					solved--;
				}
			}
			if(solved == N) break;
		}
		
		for(int i = 0; i < N; i++){
			printf("%d ",ans[i]+1);
		}
		putchar('\n');
	}
	return 0;
}
