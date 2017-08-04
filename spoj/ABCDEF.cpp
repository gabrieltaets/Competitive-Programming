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
	int s[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&s[i]);
	}
	vi mapa1, mapa2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				mapa1.pb(s[i] * s[j] + s[k]);
				if(s[i]) mapa2.pb(s[i] * s[j] + s[i] * s[k]);
			}
		}
	}
	sort(mapa1.begin(), mapa1.end());
	sort(mapa2.begin(), mapa2.end());
	vi::iterator it;
	ll sum = 0;
	for(int i = 0; i < mapa1.size(); i++){
		sum += upper_bound(mapa2.begin(), mapa2.end(), mapa1[i]) - lower_bound(mapa2.begin(), mapa2.end(), mapa1[i]);
	}
	printf("%lld\n",sum);
	return 0;
}
