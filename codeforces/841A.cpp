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
	bool ans = true;
	int n, k;
	cin >> n >> k;
	map<char,int> f;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		f[c]++;
		if(f[c] > k) ans = false;
	}
	printf("%s\n",ans?"YES":"NO");
	return 0;
}
