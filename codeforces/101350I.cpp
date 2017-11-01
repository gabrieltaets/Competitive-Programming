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
		double R, a;
		cin >> R >> a;
		double ac = a/360.0 * acos(-1.0) * R * R;
		double x = sqrt(2.0*R*R*(1.0-cos(a*acos(-1.0)/180.0)));
		double p = (x+R+R)/2.0;
		double at = sqrt(p*(p-x)*(p-R)*(p-R));
		printf("%.6lf\n",ac-at);
	}
	return 0;
}
