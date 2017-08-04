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

int main(){
	map<string,int> mapa;
	mapa["Tetrahedron"] = 4;
	mapa["Cube"] = 6;
	mapa["Octahedron"] = 8;
	mapa["Dodecahedron"] = 12;
	mapa["Icosahedron"] = 20;
	int n, cont = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		cont += mapa[str];
	}
	cout << cont << endl;
	return 0;
}
