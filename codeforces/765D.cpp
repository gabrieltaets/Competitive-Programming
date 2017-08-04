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
vi f(100035), g(100035), h(100035);
int main(){
	int n;
	cin >> n;
	bool fail = false;
	for(int i = 1; i <= n; i++){
		cin >> f[i];
	}
	int m = 1;
	map<int, int> mapa;
	for(int i = 1; i <= n; i++){
		if(mapa.insert({f[i],m}).S){
			h[m++] = f[i];
		}
	}
	for(int i = 1; i <= n; i++){
		g[i] = mapa[f[i]];
	}
	for(int i = 1; i <= n; i++){
		if(h[g[i]] != f[i]) fail = true;
	}
	for(int i = 1; i < m; i++){
		if(g[h[i]] != i) fail = true;
	}
	if(fail){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",m-1);
	for(int i = 1; i <= n; i++){
		printf("%d ",g[i]);
	}
	printf("\n");
	for(int i = 1; i < m; i++){
		printf("%d ",h[i]);
	}
	printf("\n");
	return 0;
}
