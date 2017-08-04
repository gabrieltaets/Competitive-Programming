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
	set<char> good;
	string s;
	int n, ast = -1;
	cin >> s;
	for(int i = 0; i < s.size(); i++) good.insert(s[i]);
	cin >> s;
	cin >> n;
	ast = s.size();
	for(int i = 0; i < s.size(); i++) if(s[i] == '*') ast = i;
	while(n--){
		string pat;
		cin >> pat;
		int left = 0, right = pat.size()-1;
		bool ans = true;
		for(int i = 0; i < ast; i++){
			if(s[i] == pat[left]){
				left++;
				continue;
			}
			if(s[i] == '?' && good.count(pat[left])){
				left++;
				continue;
			}
			ans = false;
			break;
		}
		for(int i = s.size()-1; i > ast; i--){
			if(s[i] == pat[right]){
				right--;
				continue;
			}
			if(s[i] == '?' && good.count(pat[right])){
				right--;
				continue;
			}
			ans = false;
			break;
		}
		for(int i = left; i <= right; i++){
			if(good.count(pat[i])){
				ans = false;
				break;
			}
		}
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}
