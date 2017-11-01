/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

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

int a, b, n;

bool test(ii x, ii y){
	return ((x.S + y.S <= b && x.F <= a && y.F <= a) || (x.S + y.S <= a && x.F <= b && y.F <= b));
}

int main(){
	scanf("%d %d %d",&n,&a,&b);
	ii seal[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d",&seal[i].F,&seal[i].S);
	}
	int maxarea = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ii x(seal[i].S, seal[i].F), y(seal[j].S, seal[j].F);
			if(test(seal[i], seal[j]) || test(seal[i], y) || test(x, seal[j]) || test(x, y))
				maxarea = max(maxarea, x.F * x.S + y.F * y.S);
		}
	}
	printf("%d\n",maxarea);
	return 0;
}
