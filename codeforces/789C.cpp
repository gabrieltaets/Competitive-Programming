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
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	ll maxVal = -LINF, sum1 = 0, sum2 = 0;
	for(int i = 0; i < n - 1; i++){
		if(i&1){
			sum1 -= abs(a[i]-a[i+1]);
			sum2 += abs(a[i]-a[i+1]);
		}
		else {
			sum1 += abs(a[i]-a[i+1]);
			sum2 -= abs(a[i]-a[i+1]);
		}
		maxVal = max(maxVal,sum1);
		maxVal = max(maxVal,sum2);
		if(sum1 < 0) sum1 = 0;
		if(sum2 < 0) sum2 = 0;
	}
	cout << maxVal << endl;
	return 0;
}
