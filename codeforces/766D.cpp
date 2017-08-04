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
 private:
  vi p, rank; 
 public:
  UnionFind(int N) { 
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }
	int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
	bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
	void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { 
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) p[y] = x; 
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
} } } };

int n, m, q;
string s[100035];
map<string, int> mapa;
set<int> ant[100035];
UnionFind UF(100035);

bool antonyms(int a, int b){
	for(set<int>::iterator it = ant[UF.findSet(a)].begin(); it != ant[UF.findSet(a)].end(); it++){
		if(*it == UF.findSet(b)) return true;
	}
	for(set<int>::iterator it = ant[UF.findSet(b)].begin(); it != ant[UF.findSet(b)].end(); it++){
		if(*it == UF.findSet(a)) return true;
	}
	return false;
}

int main(){
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		mapa[s[i]] = i;
	}
	for(int i = 0; i < m; i++){
		int t;
		string a, b;
		cin >> t >> a >> b;
		int ma = mapa[a];
		int mb = mapa[b];
		if(t == 1){
			if(!antonyms(mapa[a],mapa[b])){
				printf("Sinonyms - ");
				printf("YES\n");
				int x = UF.findSet(ma);
				int y = UF.findSet(mb);
				UF.unionSet(ma, mb);
				if(UF.findSet(ma) == x){
					for(set<int>::iterator it = ant[mb].begin(); it != ant[mb].end(); it++){
						ant[ma].insert(*it);
					}
				}
				else {
					for(set<int>::iterator it = ant[ma].begin(); it != ant[ma].end(); it++){
						ant[mb].insert(*it);
					}
				}
				printf("Resulting set: %d\n",UF.findSet(ma));
			}
			else {
				printf("NO\n");
			}
		}
		else {
			if(!UF.isSameSet(ma, mb)){
				printf("Antonyms - ");
				printf("YES\n");
				printf("Put %d on set %d\n",mb,UF.findSet(ma));
				printf("Put %d on set %d\n",ma,UF.findSet(mb));
				ant[UF.findSet(ma)].insert(UF.findSet(mb));
				ant[UF.findSet(mb)].insert(UF.findSet(ma));
			}
			else {
				printf("NO\n");
			}
		}
	}
	for(int i = 0; i < q; i++){
		string a, b;
		cin >> a >> b;
		int ma = mapa[a];
		int mb = mapa[b];
		if(UF.isSameSet(ma,mb)){
			printf("1\n");
		}
		else {
			bool flag = false;
			for(set<int>::iterator it = ant[UF.findSet(ma)].begin(); it != ant[UF.findSet(ma)].end(); it++){
				if(*it == UF.findSet(mb)){
					printf("2\n");
					flag = true;
					break;
				}
			}
			if(!flag){
				printf("3\n");
			}
		}
	}
	return 0;
}
