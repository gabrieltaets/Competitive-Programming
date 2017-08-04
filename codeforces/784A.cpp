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
	int n, x;
	cin >> n;
	vi v;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.pb(x);
	}
	sort(v.begin(), v.end());
	printf("%d",v[0]);
	for(int i = 1; i < v.size(); i++) printf(" %d",v[i]);
	printf("\n");
	return 0;
}
