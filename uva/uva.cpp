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

vi v[1000010];
int a[100010];

int main(){
	int n, m;
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
			v[a[i]].clear();
		}
		for(int i = 0; i < n; i++){
			v[a[i]].pb(i+1);
		}
		for(int i = 0; i < m; i++){
			int k, x;
			scanf("%d %d",&k,&x);
			if(k > v[x].size()) printf("0\n");
			else printf("%d\n",v[x][k-1]);
		}
	}
	return 0;
}
