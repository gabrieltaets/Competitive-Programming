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

string s(2000010, 'a');
int main(){
	int n;
	scanf("%d",&n);
	int maxs = 1;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		int k;
		scanf("%d",&k);
		for(int j = 0; j < k; j++){
			int pos;
			scanf("%d",&pos);
			pos--;
			for(int z = pos; z < pos + t.size(); z++){
				s[z] = t[z-pos];
			}
			maxs = max(maxs, pos+(int)t.size());
		}
	}
	cout << s.substr(0,maxs) << endl;
	return 0;
}
