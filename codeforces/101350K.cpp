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
		int c, n;
		scanf("%d %d",&c,&n);
		map<string, double> value;
		char cu[20];
		value["JD"] = 1;
		for(int i = 0; i < c; i++){
			double v;
			scanf("%s %lf",cu,&v);
			value[string(cu)] = v;
		}
		double sum = 0;
		for(int i = 0; i < n; i++){
			double x;
			scanf("%lf %s",&x,cu);
			sum += value[string(cu)] * x;
		}
		printf("%.6lf\n",sum);
	}
	return 0;
}
