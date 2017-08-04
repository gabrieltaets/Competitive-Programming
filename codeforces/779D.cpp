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
string t, p;
int seq[200035];
bool test(int x){
	string aux = t;
	for(int i = 0; i < x; i++){
		aux[seq[i]] = '*';
	}
	int j = 0;
	for(int i = 0; i < aux.size(); i++){
		if(aux[i] == p[j]) j++;
		if(j == p.size()) return true;
	}
	return false;
}
int main(){
	cin >> t >> p;
	for(int i = 0; i < t.size(); i++){
		cin >> seq[i];
		seq[i]--;
	}
	int lo = 0, hi = t.size(), mid, ans;
	while(lo <= hi){
		mid = (lo+hi)/2;
		if(test(mid)){
			ans = mid;
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
