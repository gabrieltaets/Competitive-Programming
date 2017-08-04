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
	int n, k;
	double x;
	cin >> n >> k;
	int qtd = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		qtd += (int)ceil(x/k);
	}
	printf("%d\n",(int)ceil(qtd/2.0));
	return 0;
}
