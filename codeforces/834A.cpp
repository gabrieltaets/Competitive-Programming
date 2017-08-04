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
	char start, end;
	cin >> start >> end;
	int n;
	cin >> n;
	int mapa[120];
	mapa[0] = 'v';
	mapa[1] = '<';
	mapa[2] = '^';
	mapa[3] = '>';
	mapa['v'] = 0;
	mapa['<'] = 1;
	mapa['^'] = 2;
	mapa['>'] = 3;
	int ans = 0;
	if((mapa[start] + n)%4 == mapa[end]) ans++;
	if((mapa[start] + 4 - (n%4))%4 == mapa[end]) ans--;
	if(ans < 0) printf("ccw\n");
	if(ans > 0) printf("cw\n");
	if(!ans) printf("undefined\n");
	return 0;
}
