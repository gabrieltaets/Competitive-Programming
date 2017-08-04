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

int tr[600000], a[150000];

void build(int no, int l, int r, int op){
	if(l == r) {
		tr[no] = a[l];
		return;
	}
	int esq = 2*no, dir = 2*no+1, mid = (l+r)/2;
	build(esq, l, mid, !op);
	build(dir, mid+1, r, !op);
	tr[no] = op ? tr[esq] | tr[dir] : tr[esq] ^ tr[dir];
}

void update(int no, int l, int r, int pos, int v, int op){
	if(pos < l || pos > r) return;
	if(l == r){
		tr[no] = v;
		return;
	}
	int esq = 2*no, dir = 2*no+1, mid = (l+r)/2;
	update(esq, l, mid, pos, v, !op);
	update(dir, mid+1, r, pos, v, !op);
	tr[no] = op ? tr[esq] | tr[dir] : tr[esq] ^ tr[dir];
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= (1 << n); i++){
		scanf("%d",&a[i]);
	}
	build(1, 1, (1 << n), !((n+1)&1));
	while(m--){
		int pos, v;
		scanf("%d %d",&pos,&v);
		update(1, 1, (1 << n), pos, v, !((n+1)&1));
		printf("%d\n",tr[1]);
	}
	return 0;
}
