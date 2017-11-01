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

int n, q;
int a[100010];

int main(){
	scanf("%d %d",&n,&q);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1) {
			int x, k, at;
			scanf("%d %d",&x,&k);
			at = --x;
			for(int i = x; k && i < n; i++){
				if(i - at > 100) break;
				if(a[i] > a[at]){
					at = i;
					k--;
				}
			}
			printf("%d\n",at+1);
		}
		else {
			int l, r, x;
			scanf("%d %d %d",&l,&r,&x);
			for(int i = l-1; i < r; i++){
				a[i] += x;
			}
		}
	}
	return 0;
}
