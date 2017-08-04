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

ll v[500005];
int third[500005];
ll sum[500005];
int main(){
	int n;
	cin >> n;
	v[0] = 0;
	memset(third, 0, sizeof third);
	ll cont = 0;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		v[i] = v[i] + v[i - 1];
	}
	if(v[n] % 3) {
		printf("0\n");
		return 0;
	}
	
	for(int i = 1; i < n; i++){
		if(v[n] - v[i] == v[n] / 3){
			third[i] = 1;
		}
	}
	
	sum[n] = 0;
	for(int i = n; i > 0; i--){
		sum[i-1] = sum[i]+third[i];
	}
	for(int i = 1; i <= n; i++){
		if(v[i] == v[n]/3) cont += sum[i];
	}
	cout << cont << endl;
	return 0;
}
