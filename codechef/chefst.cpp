#include <bits/stdc++.h>
using namespace std;
int main(){
	int T, m;
	long long n1, n2, s;
	cin >> T;
	while(T--){
		cin >> n1 >> n2 >> m;
		if(n1 < n2) swap(n1,n2);
		s = (long long) m*(1LL+m)/2LL;
		if(s <= n2){
			printf("%lld\n",n1+n2-2*s);
		}
		else {
			printf("%lld\n",n1-n2);
		}
	}
	return 0;
}