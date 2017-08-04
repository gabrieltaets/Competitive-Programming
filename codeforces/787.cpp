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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a%2==0 && c%2==0 && ((b&1)^(d&1))){
		printf("-1\n");
		return 0;
	}
	for(int i = max(b,d); i < 100000000; i++){
		if((i-b)%a == 0 && (i-d)%c == 0) {
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
