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
	int ini, a, b, c;
	while(scanf("%d %d %d %d",&ini,&a,&b,&c)!=EOF && (ini||a||b||c)){
		int qtd = 720;
		a = a*9;
		b *= 9;
		c *= 9;
		ini *= 9;
		qtd += ini - a;
		if(a > ini) qtd += 360;
		qtd += 360;
		qtd += b - a;
		if(b < a) qtd += 360;
		qtd += b - c;
		if(c > b) qtd += 360;
		printf("%d\n",qtd);
	}
	return 0;
}
