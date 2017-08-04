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
	int T;
	scanf("%d",&T);
	while(T--){
		string s;
		cin >> s;
		pair<ll,ll> left(0,1), right(1,0), mid(1, 1);
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R'){
				left = mid;
			}
			else {
				right = mid;
			}
			mid = mp(left.F + right.F, left.S + right.S);
		}
		printf("%lld/%lld\n",mid.F,mid.S);
	}
	return 0;
}
