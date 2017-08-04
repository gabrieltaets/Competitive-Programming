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
	while(scanf("%d",&n)!=EOF && n){
		int book[n], M;
		for(int i = 0; i < n; i++) scanf("%d",&book[i]);
		sort(book,book+n);
		scanf("%d",&M);
		int i = 0, j = n - 1;
		ii ans(0,n-1);
		while(i < j){
			if(book[i] + book[j] < M) i++;
			else if(book[i] + book[j] > M) j--;
			else ans = {i++, j--};
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",book[ans.F],book[ans.S]);
	}
	return 0;
}
