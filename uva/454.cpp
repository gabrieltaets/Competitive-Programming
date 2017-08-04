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
	cin >> T;
	getchar();
	getchar();
	while(T--){
		vector<string> v;
		string x;
		while(getline(cin,x) && !x.empty()){
			v.pb(x);
		}
		sort(v.begin(), v.end());
		int freq[100][300];
		memset(freq,0,sizeof freq);
		for(int i = 0; i < v.size(); i++){
			for(int j = 0; j < v[i].size(); j++){
				if(v[i][j] == ' ') continue;
				freq[i][v[i][j]]++;
			}
		}
		vii ans;
		for(int i = 0; i < v.size(); i++){
			for(int j = i+1; j < v.size(); j++){
				int k;
				for(k = 0; k < 300; k++){
					if(freq[i][k] != freq[j][k]) break;
				}
				if(k == 300){
					ans.pb({i,j});
				}
			}
		}
		for(int i = 0; i < ans.size(); i++){
			cout << v[ans[i].F] << " = " << v[ans[i].S] << endl;
		}
		if(T) cout << endl;
	}
	return 0;
}
