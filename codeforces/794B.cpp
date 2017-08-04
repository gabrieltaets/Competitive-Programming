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
	int n;
	double h, at, e;
	cin >> n >> h;
	at = 0.5*h;
	e = at/n;
	for(int i = 1; i < n; i++){
		double p = sqrt(2*h*i*e);
		printf("%.7lf ",p);
	}
	return 0;
}
