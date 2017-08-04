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
	int p = 0, ca = 0, cb = 0, cont = 0;
	for(int i = 0; i < s.size(); i++){
		if(i >= 4 && s[i-4] == 'a') ca--;
		if(i >= 4 && s[i-4] == 'b') cb--;
		if((ca == 3 || cb == 3) && p == 0) cont++;
		if(s[i] == 'a') ca++;
		if(s[i] == 'b') cb++;
		p++;
		if(p >= n) p -= n;
	}
	printf("%d\n",cont);
	return 0;
}
