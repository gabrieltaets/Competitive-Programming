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
	vi v;
	int x;
	while(scanf("%d",&x)!=EOF){
		vi::iterator it;
		for(it = v.begin(); it != v.end() && *it < x; it++);
		v.insert(it, x);
		int m = v[v.size()/2];
		if(v.size()%2==0){
			m += v[v.size()/2-1];
			m /= 2;	
		}
		printf("%d\n",m);
	}
	return 0;
}
