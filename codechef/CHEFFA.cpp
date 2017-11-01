/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

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

int n;
set<vi> s;

void solve(vi v){
	if(!s.insert(v).S) return;
	for(int i = 0; i < v.size() - 1; i++){
		if(v[i] && v[i+1]){
			vi x(v.begin(), v.end());
			x[i]--; x[i+1]--;
			if(i == v.size()-2) x.pb(1);
			else x[i+2]++;
			solve(x);
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		s.clear();
		scanf("%d",&n);
		vi v;
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d",&x);
			v.pb(x);
		}
		solve(v);
		printf("%d\n",s.size());

	}
	return 0;
}
