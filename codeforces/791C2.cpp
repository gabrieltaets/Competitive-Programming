///José Luiz da Silva Neto
///Computer Engineering - Federal University of Itajubá
#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define DEG_to_RAD(X)   (X * PI / 180)
#define MOD 1000000007LL
 
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector < pii > vii;
typedef long long ll;
typedef unsigned long long ull;	

#define D(x) cout << #x << " = " << x << endl;
#define C(x) cout << "Chegou aqui " << x << endl;
#define pn printf("\n");
#define ps printf(" ");

int vx[] = {1,0,-1,0};
int vy[] = {0,1,0,-1};

vector <string> base;

void init() {
	for(int i = 'A';i <= 'Z';i++) {
		string x;
		x.pb(i);
		base.pb(x);
	}
	for(int i = 'a';i <= 'z';i++) {
		string x;
		x.pb('A');
		x.pb(i);
		base.pb(x);
	}
}

int main() {
	int k,n;
	cin >> k >> n;
	int x = k-n+1;
	init();
	int v[x];
	for(int i = 0;i < x;i++) {
		string y;
		cin >> y;
		if(y == "YES") v[i] = 1;
		else v[i] = 0;
	}	
	vector <string> res;
	int pos = 0;
	if(v[x-1] == 1) {
		for(int i = 0;i < n;i++) {
			res.pb(base[i]);
			pos = i;
		}
	}
	else {
		res.pb(base[0]);
		for(int i = 0;i < n-1;i++) {
			res.pb(base[i]);
			pos = i;
		}
	}

	for(int i = x-2;i >= 0;i--) {
		if(v[i] == 1) {
			res.pb(base[pos+1]);
			pos++;
			pos%=k;
		}
		else {
			res.pb(res[res.size()-n+1]);
		}
	}
	for(int i = res.size()-1;i >= 0;i--) {
		cout << res[i];
		if(i != 0)
			ps;
	}
	pn;
	return 0;
}