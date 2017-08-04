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
int dp[5005][5005], check[5005][5005];
bool memo[5005][5005];

int preprocess(int l, int r){
	if(l > r) return 0;
	if(check[l][r]) return check[l][r];
	if(l == r) return check[l][r] = 1;
	if(l == r - 1) return check[l][r] = (s[l] == s[r] ? 1 : 2);
	check[l][r] = 2;
	if(preprocess(l+1, r-1) == 1 && s[l] == s[r]) check[l][r] = 1;
	return check[l][r];
}

int solve(int l, int r){
	if(l > r) return 0;
	if(memo[l][r]) return dp[l][r];
	memo[l][r] = 1;
	if(l == r) return dp[l][r] = 1;
	dp[l][r] = solve(l, r-1) + solve(l+1, r) - solve(l+1, r-1) + (check[l][r] == 1);
	return dp[l][r];
}

int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size(); j++){
			preprocess(i, j);
		}
	}
	solve(0, s.size()-1);
	int q;
	scanf("%d",&q);
	while(q--){
		int l, r;
		scanf("%d %d",&l,&r);
		l--; r--;
		printf("%d\n",solve(l,r));
	}
	return 0;
}
