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
int main(){
	while(scanf("%d",&n) == 1 && n){
		int v[n];
		for(int i = 0; i < n; i++){
			scanf("%d",&v[i]);
		}
		int maxSum = 0, a = 0;
		for(int i = 0; i < n; i++){
			a += v[i];
			maxSum = max(maxSum, a);
			if(a < 0) a = 0;
		}
		if(!maxSum) printf("Losing streak.\n");
		else printf("The maximum winning streak is %d.\n",maxSum);
	}
	return 0;
}
