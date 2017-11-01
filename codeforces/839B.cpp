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
	int n, k;
	cin >> n >> k;
	int a[1010];
	int s = 0;
	for(int i= 0; i < k; i++){
		cin >> a[i];
		if(a[i]%2) a[i]++;
		s += a[i]/2;
	}
	printf("%s\n",s<=4*n?"yes":"no");
	return 0;
}
