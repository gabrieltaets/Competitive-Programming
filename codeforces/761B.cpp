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
	int n, l;
	cin >> n >> l;
	int k[100], s[100];
	int kl, sl;
	for(int i = 0; i < n; i++){
		scanf("%d",&k[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&s[i]);
	}
	kl = k[n-1], sl = s[n-1];
	for(int i = n-1; i > 0; i--){
		k[i] -= k[i-1];
		s[i] -= s[i-1];
	}
	k[0] += l - kl;
	s[0] += l - sl;	
	for(int i = 0; i < n; i++){
		int j = i;
		int z = 0;
		bool flag = true;
		do {
			if(k[j] != s[z]) flag = false;
			j++;
			z++;
			if(j == n) j = 0;
		} while(j != i && flag);
		if(flag){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
