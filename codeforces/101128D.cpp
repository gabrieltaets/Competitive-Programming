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
	int n, m;
	int prob[50];
	memset(prob, 0, sizeof prob);
	cin >> n >> m;
	int maxp = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			prob[i+j]++;
			maxp = max(maxp, prob[i+j]);
		}
	}
	for(int i = 1; i <= n+m; i++){
		if(prob[i] == maxp) printf("%d\n",i);
	}
	return 0;
}
