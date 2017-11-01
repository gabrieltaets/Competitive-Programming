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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n, x, a;
	bool less = false, more = false, exact = false;
	scanf("%d %d",&n,&x);
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		if(a < x) less = true;
		if(a > x) more = true;
		if(a == x) exact = true;
	}
	printf("%d\n",exact?1:(more&&less?2:-1));
	return 0;
}
