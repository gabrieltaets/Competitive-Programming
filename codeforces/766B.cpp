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
	int a[n+50];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0; i < n-2; i++){
		if(a[i] + a[i+1] > a[i+2]){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
