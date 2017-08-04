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
	string str1, str2;
	bool flag = false;
	while(cin >> str1 >> str2){
		if(flag) cout << endl;
		flag = true;
		if(str1.size() > str2.size()) swap(str1, str2);
		int m = min(str1.size(), str2.size());
		set<string> ans;
		for(int i = m; i > 0; i--){
			for(int j = 0; j + i <= m; j++){
				string x = str1.substr(j,i);
				if(str2.find(x) != -1) ans.insert(x);
			}
			if(!ans.empty()) break;
		}
		if(ans.empty()){
			printf("No common sequence.\n");
			continue;
		}
		for(set<string>::iterator it = ans.begin(); it != ans.end(); it++){
			cout << *it << endl;
		}
	}
	return 0;
}
