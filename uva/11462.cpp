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
		int freq[100];
		memset(freq, 0, sizeof freq);
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d",&x);
			freq[x]++;
		}
		bool flag = false;
		for(int i = 0; i < 100; i++){
			if(!freq[i]) continue;
			for(int j = 0; j < freq[i]; j++){
				if(flag) printf(" ");
				flag = true;
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
