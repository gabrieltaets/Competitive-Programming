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
	int n, total = 0, ate = -1;
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		if(ate < x) ate = x;
		total += min(10,10 - ate + x);
		ate = x + 10;
	}
	
	printf("%d\n",total);
	return 0;
}
