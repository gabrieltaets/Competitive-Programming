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
		int n;
		scanf("%d",&n);
		ll coin[1010];
		for(int i = 0; i < n; i++){
			scanf("%lld",&coin[i]);
		}
		ll sum = coin[n-1];
		int qtd = 1;
		for(int i = n - 2; i >= 0; i--){
			ll x = sum + coin[i];
			int tmp = 0;
			printf("**\n");
			
			for(int j = n-1; j >= 0; j--){
				if(x < coin[j]) continue;
				x %= coin[j];
				tmp++;
				printf("took %d\n",coin[j]);
			}
			if(tmp > qtd){
				qtd = tmp;
				sum += coin[i];
			}
		}
		printf("%d\n",qtd);
	}
	return 0;
}
