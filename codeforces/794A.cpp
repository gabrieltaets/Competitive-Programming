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
	int a, b, c, n, x, cont = 0;
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		if(x > b && x < c) cont++;
	}
	printf("%d\n",cont);
	return 0;
}
