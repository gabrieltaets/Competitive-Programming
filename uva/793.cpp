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
  	vi p, rank;
  	UnionFind(int n){
  		p.assign(n, 0);
  		rank.assign(n, 0);
  		for(int i = 0; i < n; i++) p[i] = i;
  	}
  	int findSet(int i){
  		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  	}
  	bool isSameSet(int i, int j){
  		return findSet(i) == findSet(j);
  	}
  	void unionSet(int i, int j){
  		if(isSameSet(i, j)) return;
  		i = findSet(i);
  		j = findSet(j);
  		if(rank[i] > rank[j]) {
  			p[j] = i;
  			return;
  		}
  		p[i] = j;
  		if(rank[i] == rank[j]) rank[j]++;
  	}
};

int main(){
	int T, flag = 0;
	scanf("%d",&T);
	while(T--){
		if(flag) printf("\n");
		flag = 1;
		int n, s = 0, u = 0;
		char c;
		scanf("%d",&n);
		getchar();
		UnionFind UF(n+1);
		while((c = getchar()) && (c == 'c' || c == 'q')){
			int x, y;
			scanf("%d %d",&x,&y);
			getchar();
			if(c == 'c') UF.unionSet(x,y);
			else {
				if(UF.isSameSet(x, y)) s++;
				else u++;
			}
		}
		printf("%d,%d\n",s,u);
	}
	return 0;
}
