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

string str;

typedef struct stNo {
	int x, y, z;
	stNo(int a = 0, int b = 0, int c = 0){
		x = a; y = b; z = c;
	}
	void set(int p){
		if(str[p] == '(') x++;
		if(str[p] == ')') y++;
	}
	void set(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	}
} noArv;

noArv tr[4000035];

void build(int no, int l, int r){
	if(l == r) {
		tr[no].set(l);
		return;
	}
	int esq = no*2, dir = no*2+1, mid = (l+r)/2;
	build(esq, l, mid);
	build(dir, mid+1, r);
	int made = min(tr[esq].x, tr[dir].y);
	tr[no].x = tr[esq].x + tr[dir].x - made;
	tr[no].y = tr[esq].y + tr[dir].y - made;
	tr[no].z = tr[esq].z + tr[dir].z + made;
}

noArv query(int no, int l, int r, int i, int j){
	if(i > r || j < l) return tr[0];
	if(l >= i && r <= j) return tr[no];
	int dir = no*2+1, esq = no*2, mid = (l+r)/2, made;
	noArv x1 = query(esq, l, mid, i, j);
	noArv x2 = query(dir, mid + 1, r, i, j);
	made = min(x1.x, x2.y);
	noArv x(x1.x + x2.x - made, x1.y + x2.y - made, x1.z + x2.z + made);
	return x;
}

int main(){
	cin >> str;
	build(1,0,str.size()-1);
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		a--; b--;
		printf("%d\n",query(1,0,str.size()-1,a,b).z*2);
	}
	return 0;
}
