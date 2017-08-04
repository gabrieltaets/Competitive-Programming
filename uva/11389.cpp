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
	int n, d, r;
	while(scanf("%d %d %d",&n,&d,&r) == 3 && (n || d || r)){
		int day[n], night[n];
		for(int i = 0; i < n; i++) scanf("%d",&day[i]);
		for(int i = 0; i < n; i++) scanf("%d",&night[i]);
		sort(day,day+n); 
		sort(night,night+n);
		int ot = 0;
		for(int i = 0; i < n; i++){
			int total = day[i] + night[n-i-1];
			if(total > d) ot += (total-d)*r;
		}
		printf("%d\n",ot);
	}
	return 0;
}
