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
	string a, b;
	while(getline(cin,a)){
		getline(cin,b);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		string ans;
		int i = 0, j = 0;
		while(i < a.size() && j < b.size()){
			if(a[i] == b[j]){
				ans.pb(a[i]);
				i++; j++;
			}
			else if(a[i] > b[j]) j++;
			else i++;
		}
		cout << ans << endl;
	}
	return 0;
}
