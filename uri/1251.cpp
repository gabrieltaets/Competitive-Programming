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
	string s;
	int flag = 0;
	while(cin >> s){
		if(flag) printf("\n");
		flag = 1;
		int freq[130];
		memset(freq,0,sizeof(freq));
		freq[0]= INF;
		for(int i=0; i<s.size();i++){
			freq[s[i]]++;
		}
		while(1){
			int m = 0;
			for(int i=0; i<130; i++){
				if(freq[i] && freq[i]<=freq[m]){
					m=i;
				}
			}
			if(freq[m]==INF){
				break;
			}
			else{
				printf("%d %d\n", m, freq[m]);
				freq[m] = 0;
			}
			
		}
		
		
	}
	
	return 0;
}
