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
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		int x;
		scanf("%d",&x);
		bool ans = true;
		for(int i = 1; i < N; i++){
			int y;
			scanf("%d",&y);
			if((x&1) != (y&1)) ans = false;
		}
		printf("%s\n",ans?"yes":"no")
	}
	return 0;
}
