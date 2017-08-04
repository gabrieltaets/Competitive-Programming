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
	string ans;
	for(int i = 0; i < n; i++){
		if(i%4==0 || i%4==1) ans.pb('a');
		else ans.pb('b');
	}
	cout << ans << endl;
	return 0;
}
