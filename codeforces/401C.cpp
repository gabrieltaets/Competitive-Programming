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
	scanf("%d %d",&n,&m);
	if(m < n - 1 || m > 2*n + 2) return !printf("-1\n");
	int flag0 = 0, flag1 = 0;
	while(n + m){
		if(flag1 == 2 || ((!m || n/m) && !flag0)){
			printf("0");
			flag0 = 1;
			flag1 = 0;
			n--;
			continue;
		}
		printf("1");
		m--;
		flag0 = 0;
		flag1++;
	}
	return 0;
}
