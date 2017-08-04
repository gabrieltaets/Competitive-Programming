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
	int x, y, a, b;
	while(scanf("%d %d %d %d",&x,&y,&a,&b) && (x | y | a | b)){
		int k1 = b/x - (a-1)/x;
		int k2 = b/y - (a-1)/y;
		int k3 = b/(x*y/__gcd(x,y)) - (a-1)/(x*y/__gcd(x,y));
		printf("%d\n",k1+k2-k3);
	}
	return 0;
}
