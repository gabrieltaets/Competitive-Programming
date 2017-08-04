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

class UnionFind {
  public:
  	vi p, rank, size;
  	UnionFind(int n){
  		p.assign(n, 0);
  		rank.assign(n, 0);
  		size.assign(n, 1);
  		for(int i = 0; i < n; i++) p[i] = i;
  	}
  	int findSet(int i){
  		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  	}
  	bool isSameSet(int i, int j){
  		return findSet(i) == findSet(j);
  	}
  	void unionSet(int i, int j){
  		if(isSameSet(i,j)) return;
  		int x = findSet(i), y = findSet(j);
  		if(rank[x] > rank[y]) {
  			size[x] += size[y];
  			p[y] = x;
  			return;
  		}
  		p[x] = y;
  		size[y] += size[x];
  		if(rank[x] == rank[y]) rank[y]++;
  	}
  	int setSize(int i){
  		return size[findSet(i)];
  	}

};

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		map<string, int> mapa;
		int cont = 0;
		UnionFind UF(n*2);
		for(int i = 0; i < n; i++){
			string a, b;
			cin >> a >> b;
			if(mapa.find(a) == mapa.end()){
				mapa[a] = cont++;
			}
			if(mapa.find(b) == mapa.end()){
				mapa[b] = cont++;
			}
			UF.unionSet(mapa[a], mapa[b]);
			printf("%d\n",UF.setSize(mapa[a]));
		}
	}
	return 0;
}
