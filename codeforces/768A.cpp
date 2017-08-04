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
	int a[n];
	int mi = INF, ma = -1, cont = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mi = min(mi,a[i]);
		ma = max(ma,a[i]);
	}
	for(int i = 0; i < n; i++){
		if(a[i] > mi && a[i] < ma) cont++;
	}
	cout << cont << endl;
	return 0;
}
