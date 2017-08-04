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
	int n, a;
	while(scanf("%d %d",&n,&a) && (n|a)){
		int c[n], s = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&c[i]);
			s += c[i];
		}
		if(s == a){
			printf(":D\n");
			continue;
		}
		if(s < a){
			printf("-.-\n");
			continue;
		}
		double lo = 0, hi = 10000, h = -1;
		while(hi - lo >= 0.0001 && h == -1){
			double mid = (lo+hi)/2.0, t = 0;
			for(int i = 0; i < n; i++){
				t += max(0.0, c[i]-mid);
			}
			if(fabs(t-a) < 0.001) h = mid;
			if(t > a) lo = mid + 0.00001;
			else hi = mid - 0.00001;
		}
		printf("%.4lf\n",h);
	}
	return 0;
}
