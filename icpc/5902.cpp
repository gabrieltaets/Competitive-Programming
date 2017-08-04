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

int tree[800010];
int pos[100010];

void build(int no, int l, int r){
	tree[no] = 0;
	if(l == r) return;
	int esq = 2*no, dir = 2*no+1, mid = (l + r)/2;
	build(esq, l, mid);
	build(dir, mid+1, r);
}

void update(int no, int l, int r, int p){
	if(l > r) return;
	if(l == r){
		tree[no]++;
		return;
	}
	int esq = no*2, dir = no*2+1, mid = (l+r)/2;
	if(p > mid) update(dir, mid+1, r, p);
	else update(esq, l, mid, p);
	tree[no] = tree[esq] + tree[dir];
}

int query(int no, int l, int r, int i, int j){
	if(l > j || r < i) return 0;
	if(l >= i && r <= j) return tree[no];
	int esq = no*2, dir = no*2+1, mid = (l+r)/2;
	return query(dir, mid+1, r, i, j) + query(esq, l, mid, i, j);
}

int main(){
	int n, m, t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= n; i++) pos[i] = n - i + 1;
		build(1, 1, n+m);
		for(int i = 0; i < m; i++){
			int x;
			scanf("%d",&x);
			int above = n + i - pos[x] - query(1, 1, n + m, pos[x], n+m);
			if(i) printf(" ");
			printf("%d",above);
			update(1, 1, n+m, pos[x]);
			pos[x] = n+i+1;
		}
		printf("\n");
	}
	return 0;
}
