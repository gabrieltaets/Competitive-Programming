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

typedef struct stST {
	int val, q13, q7;
	stST(){
		val = 0;
		q7 = q13 = -1;
	}
} ST;

ST tr[4*200010], lazy[4*200010];
int a[200010];

void build(int no, int l, int r){
	int esq = no*2, dir = no*2+1, mid = (l+r)/2;
	if(l == r){
		tr[no].val = a[r];
		tr[no].q13 = (a[r] == 13);
		tr[no].q7 = (a[r] == 7);
		return;
	}
	build(esq, l, mid);
	build(dir, mid+1, r);
	tr[no].val = tr[esq].val + tr[dir].val;
	tr[no].q13 = tr[esq].q13 + tr[dir].q13;
	tr[no].q7 = tr[esq].q7 + tr[dir].q7;
}

void propagate(int no){
	int esq = 2*no, dir = 2*no+1;
	lazy[no].val = 0;
	if(lazy[esq].val){
		
	}

}

void update(int no, int l, int r, int i, int v){
	int esq = 2*no, dir = 2*no+1, mid = (l+r)/2;
	if(i > r || i < l) return;
	if(l == r){
		return;
	}
	update(esq, l, mid, i, v);
	update(dir, mid+1, r, i, v);
}

void update(int no, int l, int r, int i, int j, int z, int v){
	int esq = 2*no, dir = 2*no+1, mid = (l+r)/2, dif;
	if(i > r || j < l) return;
	if(l >= i && r <= j){
		if(lazy[no].val) propagate(no);
		lazy[no].val = 1;
		if(z == 7) {
			if(v == 13) tr[no].q13 = tr[no].q7;
			dif = tr[no].q7 * v - tr[no].q7 * 7;
			tr[no].q7 = 0;
			lazy[no].q7 = v;
		}
		else {
			if(v == 7) tr[no].q7 = tr[no].q13;
			dif = tr[no].q13 * v - tr[no].q13 * 13;
			tr[no].q13 = 0;
			lazy[no].q13 = v;
		}
		tr[no].val += dif;
		if(i != j) propagate(no);
		return;
	}
	if(lazy[no].val) propagate(no);
	update(esq, l, mid, i, j, z, v);
	update(dir, mid+1, r, i, j, z, v);
}

int query(int no, int l, int r, int i, int j){
	int esq = 2*no, dir = 2*no+1, mid = (l+r)/2;
	if(i > r || j < l) return 0;
	if(l >= i && r <= j){
		return tr[no].val;
	}
	if(lazy[no].val) propagate(no);
	return query(esq, l, mid, i, j) + query(dir, mid+1, r, i, j);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	int q;
	build(1, 1, n);
	scanf("%d",&q);
	for(int i = 0; i < q; i++){
		int cho, qi, qj, qz, qv;
		scanf("%d",&cho);
		if(cho == 1) {
			scanf("%d %d",&qi,&qv);
			update(1, 1, n, qi, qv);
		}
		else if(cho == 2){
			scanf("%d %d %d %d",&qi,&qj,&qz,&qv);
			if(qz != qv) update(1, 1, n, qi, qj, qz, qv);
		}
		else {
			scanf("%d %d",&qi,&qj);
			printf("%d\n",query(1, 1, n, qi, qj));
		}
	}
	return 0;
}
