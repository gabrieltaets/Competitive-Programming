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

class Persistent {
  public:
	vi tree;
	vi esq;
	vi dir;
	vi root;
	int cont;
	Persistent(int n){
		cont = 1;
		tree.resize(40*n);
		esq.resize(40*n);
		dir.resize(40*n);
		root.pb(1);
	}
	void build(int *arr, int no, int l, int r){
		int mid = (l+r)/2;
		if(l == r){
			tree[no] = arr[r];
			return;
		}
		esq[no] = ++cont;
		dir[no] = ++cont;
		build(arr, esq[no], l, mid);
		build(arr, dir[no], mid+1, r);
		tree[no] = tree[esq[no]] + tree[dir[no]];
	}
	int persist(int *arr, int no, int l, int r, int p){
		if(p > r || p < l) return no;
		int novo = ++cont, mid = (l+r)/2;
		if(l == r){
			tree[novo] = arr[p];
			return novo;
		}
		esq[novo] = persist(arr, esq[no], l, mid, p);
		dir[novo] = persist(arr, dir[no], mid + 1, r, p);
		tree[novo] = tree[esq[novo]] + tree[dir[novo]];
		return novo;
	}
	int query(int i, int j, int l, int r, int k){
		if(k < 1 || k > tree[j] - tree[i]) return -1;
		if(l == r) return r;
		int mid = (l+r)/2;
		int x = query(esq[i], esq[j], l, mid, k);
		int y = query(dir[i], dir[j], mid+1, r, k - (tree[esq[j]] - tree[esq[i]]));
		return max(x, y);
	}
};

int a[100010];
int f[100010];
int freq[100010];
map<int,int> mapa;
int n, m;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i <= n; i++){
		scanf("%d",&a[i]);
		f[i] = a[i];
	}
	sort(f+1,f+n+1);
	for(int i = 1; i <= n; i++){
		mapa[f[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		a[i] = mapa[a[i]];
	}
	Persistent seg(n);
	vi root(n+10);
	root[0] = 1;
	seg.build(freq, 0, 1, n);

	for(int i = 1; i <= n; i++){
		freq[a[i]]++;
		root[i] = seg.persist(freq, root[i-1], 1, n, a[i]);
	}
	for(int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);

		printf("%d\n",f[seg.query(root[a-1],root[b],1,n,c)]);
	}
	return 0;
}
