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

string s;
int pd[5010][5010];
int ans[5010];

int solve(int l, int r){
	//printf("solve(%d, %d)\n",l,r);
	if(l < 0 || r >= s.size() || l > r) return 0;
	if(pd[l][r] != -1) return pd[l][r];
	if(l == r) {
		ans[1]++;
		return pd[l][r] = 1;
	}
	int sz = r - l + 1;
	int mid = l + sz/2;
	int ql = solve(l, mid - 1);
	int qr = solve(mid + (sz & 1), r);
	//printf("ql = %d, qr = %d\n",ql,qr);
	pd[l][r] = 0;
	if((sz <= 2 || solve(l + 1, r - 1)) && s[l] == s[r]) {
		//printf("palindrome\n");
		pd[l][r] = min(ql, qr) + 1;
		ans[pd[l][r]]++;
	}
	return pd[l][r];
}

int main(){
	memset(pd, -1, sizeof pd);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size(); j++){
			if(j + i >= s.size()) break;
			//printf("Calling solve(%d, %d)\n", j, j + i);
			solve(j, j + i);
		}
	}
	for(int i = s.size(); i > 0; i--) ans[i] += ans[i + 1];
	for(int i = 1; i <= s.size(); i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
