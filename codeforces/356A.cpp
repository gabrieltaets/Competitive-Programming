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

int tr[1200010];
int a[300010];

void update(int no, int l, int r, int i, int j, int v){
	if(r < i || l > j || tr[no]) return;
	if(l >= i && r <= j){
		if(!tr[no]) tr[no] = v;
		return;
	}
	int esq = no*2, dir = no*2+1, mid = (l+r)/2;
	update(esq, l, mid, i, j, v);
	update(dir, mid+1, r, i, j, v);
}

void propagate(int no, int l, int r){
	if(l == r) return;
	int esq = no*2, dir = no*2+1, mid = (l+r)/2;
	if(!tr[esq]) tr[esq] = tr[no];
	if(!tr[dir]) tr[dir] = tr[no];
	propagate(esq, l, mid);
	propagate(dir, mid+1, r);
}

int query(int no, int l, int r, int pos){
	if(l == r) return tr[no];
	int mid = (l+r)/2;
	if(pos > mid) return query(no*2+1, mid+1, r, pos);
	return query(no*2,l,mid, pos);
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	while(m--){
		int l, r, x;
		scanf("%d %d %d",&l,&r,&x);
		update(1, 1, n, l, x-1, x);
		update(1, 1, n, x+1, r, x);
	}
	propagate(1, 1, n);
	for(int i = 1; i <= n; i++){
		printf("%d ",query(1, 1, n, i));
	}
	printf("\n");
	return 0;
}
