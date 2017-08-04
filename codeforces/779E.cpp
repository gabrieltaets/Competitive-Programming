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

typedef struct stExp{
	string var;
	string x1;
	string op;
	string x2;
	int val;
	stExp(){ val = 0; }
	stExp(string d, string a, string b, string c){
		var = d;
		x1 = a;
		op = b;
		x2 = c;
	}
} Exp;

int n, m;
vector<Exp> v;
map<string, int> name;
string mi, ma;

int simulate(int pos, int val){
	int cont = 0;
	v[0].val = val;
	for(int i = 1; i <= n; i++){
		if(v[i].op.empty()) {
			v[i].val = v[i].x1[pos];
			continue;
		}
		int bit, x1, x2, idx1, idx2;
		idx1 = name[v[i].x1], idx2 = name[v[i].x2];
		x1 = v[idx1].val;
		x2 = v[idx2].val;
		if(v[i].op == "AND"){
			bit = x1 & x2;
		}
		else if(v[i].op == "OR"){
			bit = x1 | x2;
		}
		else bit = x1 ^ x2;
		v[i].val = bit;
		cont += bit;
	}
	return cont;
}

int main(){
	cin >> n >> m;
	v.resize(n+1);
	for(int i = 1; i <= n; i++){
		string assign;
		cin >> v[i].var >> assign >> v[i].x1;
		if(v[i].x1[0] == '0' || v[i].x1[0] == '1'){
			cin >> v[i].op >> v[i].x2;
		}
		name[v[i].var] = i;
	}
	name["?"] = 0;
	mi.resize(m); ma.resize(m);
	for(int i = 0; i < m; i++){
		int c1 = simulate(i,0);
		int c2 = simulate(i,1);
		if(c1 == c2){
			mi[i] = '0';
			ma[i] = '0';
		}
		else if(c1 > c2){
			ma[i] = '0';
			mi[i] = '1';
		}
		else {
			mi[i] = '0';
			ma[i] = '1';
		}
	}
	cout << mi << endl << ma << endl;
	return 0;
}