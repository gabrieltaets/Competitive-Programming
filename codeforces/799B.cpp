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

typedef struct stshirt {
	int p;
	int a;
	int b;
	int u;
	bool operator< (const struct stshirt &x) const {
		return p < x.p;
	}
	stshirt(){
		u = 0;
	}
	stshirt(int _p, int _a, int _b, int _u){
		p = _p; a = _a; b = _b; u = _u;
	}
} SHIRT;

int main(){
	int n;
	scanf("%d",&n);
	SHIRT v[n];
	for(int i = 0; i < n; i++) scanf("%d",&v[i].p);
	for(int i = 0; i < n; i++) scanf("%d",&v[i].a);
	for(int i = 0; i < n; i++) scanf("%d",&v[i].b);
	sort(v,v+n);
	int c[4] = {0,0,0,0}, m;
	scanf("%d",&m);
	while(m--){
		int x, i;
		scanf("%d",&x);
		for(; c[x] < n; c[x]++){
			if(!v[c[x]].u && (v[c[x]].a == x || v[c[x]].b == x)){
				printf("%d ",v[c[x]].p);
				v[c[x]].u = 1;
				break;
			}
		}
		if(c[x] == n) printf("-1 ");
	}
	printf("\n");
	return 0;
}
