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

string a, b;

bool simula(int val){
	int j = 0, c = val;
	if(!val) return true;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == b[j]) c--;
		if(!c){
			j++;
			c = val;
		}
	}
	return j == b.size();
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cin >> a >> b;
		int lo = 0, hi = 100000, ans = 0;
		while(lo <= hi){
			int mid = (lo+hi)/2;
			if(simula(mid)){
				ans = mid;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
