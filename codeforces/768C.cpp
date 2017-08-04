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

vi s;
vi orig;
	
int main(){
	int n, k, x;
	cin >> n >> k >> x;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		s.pb(a);
		orig.pb(a);
	}
	bool flag = false;
	for(int i = 1; i <= k; i++){
		sort(s.begin(), s.end());
		for(int j = 0; j < s.size(); j += 2){
			s[j] ^= x;
		}
		if(!flag && s == orig){
			flag = true;
			int p = i;
			while(p + i < k) p += i;
			if(p > k) p -= i;
			i = p;
		}
	}
	sort(s.begin(), s.end());
	printf("%d %d\n",*(s.rbegin()), *(s.begin()));
	return 0;
}
