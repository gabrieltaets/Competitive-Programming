#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int w[1035], a[300];
int mi = INF, ma = 0, n;
string s;

int solve(int pos, int qtd){
	if(w[pos] != 0) return w[pos];
	if(pos >= n) {
		mi = min(mi,qtd);
		return 1;
	}
	int ans = 1;
	int ml = a[s[pos]];
	for(int i = pos; i < n; i++){
		ml = min(ml, a[s[i]]);
		if(ml >= i - pos + 1){
			w[pos] = (w[pos] + solve(i + 1, qtd + 1) % MOD) % MOD;
			if(i - pos + 1 > ma){
				ma = i - pos + 1;
			}
		}
		else break;
	}
	return w[pos];
}

int main(){
	cin >> n;
	cin >> s;
	memset(w,0,sizeof w);
	for(int i = 'a'; i <= 'z'; i++){
		cin >> a[i];
	}
	solve(0,0);
	mi = 1;
	for(int i = 0; i < n; i++){
		int ml = a[s[i]], j;
		for(j = i; j < n; j++){
			ml = min(ml, a[s[j]]);
			if(j - i + 1 > ml){
				i = j - 1;
				mi++;
				break;
			}
		}
	}
	
	cout << w[0] << endl << ma << endl << mi << endl;
	return 0;
}
