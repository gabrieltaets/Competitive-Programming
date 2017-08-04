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
	int n;
	while(scanf("%d",&n)!=EOF){
		vi v;
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d",&x,&y);
			for(int j = x; j <= y; j++) v.pb(j);
		}
		sort(v.begin(), v.end());
		int m;
		scanf("%d",&m);
		vi::iterator it1, it2;
		it1 = lower_bound(v.begin(), v.end(), m);
		it2 = upper_bound(v.begin(), v.end(), m);
		if(it1 == v.end() || *it1 != m) printf("%d not found\n",m);
		else printf("%d found from %d to %d\n",m,it1-v.begin(),it2-v.begin()-1);
	}
	return 0;
}
