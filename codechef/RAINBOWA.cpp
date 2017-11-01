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

int main(){
	int t, n, a[110];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		int last = 0;
		bool ans = (n >= 13);
		set<int> s;
		for(int i = 0; i < (int) ceil(n/2.0); i++){
			int cmp = n-i-1;
			if(a[i] != a[cmp] || (a[i] - last != 0 && a[i] - last != 1)){
				ans = false;
				break;
			}
			s.insert(a[i]);
			last = a[i];
		}
		ans &= (s.size() == 7);
		printf("%s\n",ans?"yes":"no");

	}
	return 0;
}
