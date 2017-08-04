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
	int n, k;
	cin >> n >> k;
	vi a(k);
	for(int i = 0; i < k; i++) cin >> a[i];
	int pl = n, cap = 0;
	map<int,int> pos;
	for(int i = 0; i <= n; i++) pos[i] = i;
	
	for(int i = 0; i < k; i++){
		int idx = (cap+(a[i]%pl))%pl;
		//printf("Removing index %d\n",idx);
		printf("%d ",pos[idx]+1);
		for(int j = pos.find(idx)->F; j < n; j++) pos[j] = pos[j+1];
		/*
		for(int j = 0; j < n-i-1; j++){
			printf("%d ",pos[j]+1);
		}
		printf("\n");
		*/
		pl--;
		cap = idx%pl;
		//printf("cap now %d (%d)\n",cap,pos[cap]+1);
		
	}
	printf("\n");
	return 0;
}
