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

int tr1[400005], tr2[400005];
vii coin, diam;

void build(int *tr, int no, int l, int r, vii &v){
	if(l == r){
		tr[no] = l;
		return;
	}
	int esq = 2*no, dir = 2*no+1, mid = (l+r)/2;
	build(tr, esq, l, mid, v);
	build(tr, dir, mid+1, r, v);
	tr[no] = (v[tr[esq]].S > v[tr[dir]].S) ? tr[esq] : tr[dir];
}

int query(int *tr, int no, int l, int r, int i, int j, vii &v){
	//printf("querying(%d, %d, %d, %d, %d)\n",no,l,r,i,j);
	if(j < l || i > r) {
		//printf("returned -1\n");
		return -1;
	}
	if(l >= i && r <= j) {
		//printf("returned %d\n",tr[no]);
		return tr[no];
	}
	int esq = 2*no, dir = 2*no+1, mid = (l+r)/2;
	int q1 = query(tr, esq, l, mid, i, j, v);
	int q2 = query(tr, dir, mid+1, r, i, j, v);
	if(q1 == -1) return q2;
	if(q2 == -1) return q1;
	//printf("query(%d, %d, %d, %d, %d) returned %d\n",no,l,r,i,j,(v[q1].S>v[q2].S)?q1:q2);
	return (v[q1].S > v[q2].S) ? q1 : q2;
}

int main(){
	int n, c, d;
	ii maxc(0,0), maxd(0,0);
	scanf("%d %d %d",&n,&c,&d);
	for(int i = 0; i < n; i++){
		int a, b;
		char t;
		scanf("%d %d %c",&a,&b,&t);
		if(t == 'C') {
			coin.pb({b,a});
			if(b <= c && a > maxc.F) maxc = mp(a,b);
		}
		else {
			diam.pb({b,a});
			if(b <= d && a > maxd.F) maxd = mp(a,b);
		}
	}
	int ans = 0;
	if(maxc.F && maxd.F) ans = maxc.F + maxd.F;
	if(coin.size() >= 2){
		sort(coin.begin(), coin.end());
		build(tr1, 1, 0, coin.size()-1, coin);
		for(int i = 0; i < coin.size(); i++){
			//printf("Selected (%d %d)\n",coin[i].S,coin[i].F);
			int lo = i+1, hi = coin.size()-1, q = -1, x;
			while(lo <= hi){
				int mid = (lo+hi)/2;
				if(coin[i].F + coin[mid].F <= c){
					q = mid;
					lo = mid+1;
				}
				else hi = mid-1;
			}
			if(q != -1){
				//printf("Binary search found (%d %d) is limit\n",coin[q].S,coin[q].F);
				x = query(tr1, 1, 0, coin.size()-1, i+1, q, coin);
				//printf("C- best match with (%d %d) is (%d %d)\n",coin[i].S, coin[i].F ,coin[x].S, coin[x].F);
				ans = max(ans, coin[x].S + coin[i].S);
			}
		}
	}
	//printf("\n\n");
	if(diam.size() >= 2){
		sort(diam.begin(), diam.end());
		build(tr2, 1, 0, diam.size()-1, diam);
		for(int i = 0; i < diam.size(); i++){
			//printf("Selected (%d %d)\n",diam[i].S, diam[i].F);
			int lo = i+1, hi = diam.size()-1, q = -1, x;
			while(lo <= hi){
				int mid = (lo+hi)/2;
				if(diam[i].F + diam[mid].F <= d){
					q = mid;
					lo = mid+1;
				}
				else hi = mid-1;
			}
			if(q != -1){
				//printf("Binary search found (%d %d) is limit\n",diam[q].S, diam[q].F);
				x = query(tr2, 1, 0, diam.size()-1, i+1, q, diam);
				//printf("D- best match with (%d %d) is (%d %d)\n",diam[i].S, diam[i].F ,diam[x].S, diam[x].F);
				ans = max(ans, diam[x].S + diam[i].S);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
