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
	scanf("%d",&n);
	string s;
	cin >> s;
	int cont = 0;
	char last;
	for(int i = 0; i < n; i++){
		last = i?s[i-1]:'0';
		if(s[i] == '0'){
			printf("%d",cont);
			cont = 0;
			continue;
		}
		cont++;
	}
	if(s[n-1] == '0' || cont) printf("%d",cont);
	return 0;
}
