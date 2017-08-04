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
	while(scanf("%d",&n) && n){
		set<string> s;
		for(int i =  0; i < n; i++){
			string x;
			cin >> x;
			s.insert(x);
		}
		printf("Falta(m) %d pomekon(s).\n",151-s.size());
	}
	return 0;
}
