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
	int n, k;
	scanf("%d %d",&n,&k);
	int a[n], s = 0, t = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		s += a[i];
	}
	while(s < (int)(k*ceil(n/2.0)+(k-1)*floor(n/2.0))){
		s += k;
		n++;
		t++;
	}
	printf("%d\n",t);
	return 0;
}
