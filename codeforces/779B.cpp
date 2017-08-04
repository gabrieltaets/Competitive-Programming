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
	string n;
	int k, q = 0, r = 0;
	cin >> n >> k;
	for(int i = n.size(); i--;){
		if(q == k) break;
		if(n[i] == '0') q++;
		else r++;
	}
	if(q != k){
		r = n.size() - (q?1:0);
	}
	printf("%d\n",r);
	return 0;
}
