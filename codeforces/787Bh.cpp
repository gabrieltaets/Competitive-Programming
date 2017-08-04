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

int ok[100035], v[100035];

int main(){
	int n,m ,i,j,nr=0,rele;
	cin >> n >> m;
	for(i = 1; i <= m; i++){
		cin >> nr;
		rele= 0;
		for(j =1; j <= nr; j++){
			cin >> v[j];
			if(ok[abs(v[j])]) rele = 1;
			ok[abs(v[j])]=1;
		}
		for(j = 1; j <= nr; j++) {
			printf("%d\n",ok[v[j]]);
			ok[v[j]] = 0;
		}
		if(!rele) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
