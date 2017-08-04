#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	int q256 = min(k2,min(k5,k6));
	int q32 = min(k2-q256,k3);
	ll sum = 256LL*q256 + 32LL*q32;
	cout << sum << endl;
	return 0;
}
