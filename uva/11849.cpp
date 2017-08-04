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
	int n, m;
	while(scanf("%d %d",&n,&m)!=EOF && (n|m)){
		set<int> s;
		int cont = 0, x;
		for(int i = 0; i < n; i++){
			scanf("%d",&x);
			s.insert(x);
		}
		for(int i = 0; i < m; i++){
			scanf("%d",&x);
			if(!s.insert(x).S) cont++;
		}
		printf("%d\n",cont);
	}
	return 0;
}
