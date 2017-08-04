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
	cin >> n >> k;
	int a[n], b[n];
	ii disc[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		disc[i] = {a[i]-b[i], i};
	}
	sort(disc,disc+n);
	ll sum = 0;
	for(int i = 0; i < k; i++){
		sum += a[disc[i].S];
	}
	for(int i = k; i < n; i++){
		sum += min(a[disc[i].S], b[disc[i].S]);
	}
	cout << sum << endl;
	return 0;
}
