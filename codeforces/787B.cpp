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

#define MAXN 20010

set<int> graph[MAXN];


int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			graph[i].insert(x);
		}
	}
	int fudeu = m;
	for(int i = 0; i < m; i++){
		for(int j = 1; j <= n; j++){
			if(graph[i].count(j) && graph[i].count(-j)) {
				fudeu--;
				break;
			}
		}
	}
	printf("%s\n",fudeu?"YES":"NO");
	return 0;
}
