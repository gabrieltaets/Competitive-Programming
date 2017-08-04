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
	int T;
	scanf("%d",&T);
	for(int caso = 1; caso <= T; caso++){
		int n[3];
		set<int> s[3], a[3];
		for(int i = 0; i < 3; i++) {
			scanf("%d",&n[i]);
			for(int j = 0; j < n[i]; j++){
				int x;
				scanf("%d",&x);
				s[i].insert(x);
			}
		}
		int ans = 0;
		for(int i = 0; i < 3; i++){
			for(set<int>::iterator it = s[i].begin(); it != s[i].end(); it++){
				int j;
				for(j = 0; j < 3; j++){
					if(i == j) continue;
					if(s[j].count(*it)) {
						break;
					}
				}
				if(j == 3) {
					a[i].insert(*it);
				}
			}
			ans = max(ans,(int)a[i].size());
		}
		printf("Case #%d:\n",caso);
		for(int i = 0; i < 3; i++){
			if(a[i].size() == ans){
				printf("%d %d",i+1,ans);
				for(set<int>::iterator it = a[i].begin(); it != a[i].end(); it++){
					printf(" %d",*it);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
