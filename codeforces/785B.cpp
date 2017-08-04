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
	int n, m;
	cin >> n;
	ii maxChess(-INF,-INF), minChess(INF,INF), minClass(INF, INF), maxClass(-INF, -INF);
	for(int i = 0; i < n; i++){
		ii ch;
		cin >> ch.F >> ch.S;
		if(ch.S == minChess.S && ch.F > minChess.F) minChess = ch;
		if(ch.S < minChess.S) minChess = ch;
		if(ch.F == maxChess.F && ch.S < minChess.S) maxChess = ch;
		if(ch.F > maxChess.F) maxChess = ch;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		ii cl;
		cin >> cl.F >> cl.S;
		if(cl.S == minClass.S && cl.F > minClass.F) minClass = cl;
		if(cl.S < minClass.S) minClass = cl;
		if(cl.F == maxClass.F && cl.S < maxClass.S) maxClass = cl;
		if(cl.F > maxClass.F) maxClass = cl;
	}
	int per = max( 0, max(
		maxClass.F - minChess.S,
		maxChess.F - minClass.S
		) );
	cout << per << endl;
	return 0;
}
