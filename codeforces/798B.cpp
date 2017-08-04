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

int n;
string s[60];

int check(int p){
	int cont = 0;
	for(int i = 0; i < n; i++){
		if(i == p) continue;
		string x = s[i];
		while(s[p] != x){
			x.pb(x[0]);
			x.erase(0,1);
			cont++;
			if(s[i] == x) return -1;
		}
	}
	return cont;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	int ans = INF;
	for(int i = 0; i < n; i++){
		ans = min(ans,check(i));
	}
	printf("%d\n",ans);
	return 0;
}
