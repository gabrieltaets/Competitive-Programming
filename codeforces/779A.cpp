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
	cin >> n;
	int a[n], b[n];
	int freq[2][6];
	memset(freq, 0, sizeof freq);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		freq[0][a[i]]++;
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		freq[1][b[i]]++;
	}
	int q = 0;
	for(int i = 1; i <= 5; i++){
		if((freq[0][i] + freq[1][i]) % 2){
			printf("-1\n");
			return 0;
		}
		q += abs(freq[0][i] - ((freq[0][i]+freq[1][i])/2));
	}
	printf("%d\n",q/2);
	return 0;
}
