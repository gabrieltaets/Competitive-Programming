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

bitset<1000005> hole;

int main(){
	int n, m, k;
	int h;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		scanf("%d",&h);
		hole[h] = 1;
	}
	int pos = 1, ans = 1;
	bool fall = hole[1];
	int x, y;
	for(int i = 0; i < k && !fall; i++){
		scanf("%d %d",&x,&y);
		if(pos == x){
			pos = y;
		}
		else if(pos == y){
			pos = x;
		}
		if(!fall && hole[pos]){
			fall = true;
			ans = pos;
		}
		else if(!fall) ans = pos;
	}
	printf("%d\n",ans);
	return 0;
}
