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
		deque<char> dq(pat.begin(), pat.end());
		int i = 0;
		bool ans = true;
		while(s[i] != '*' && i < ast){
			if(dq.empty()){
				ans = false;
				break;
			}
			if(s[i] == dq.front() || (s[i] == '?' && good.count(dq.front()))){
				dq.pop_front();
				i++;
				continue;
			}
			ans = false;
			break;
		}
		int j = s.size()-1;
		while(s[j] != '*' && j > ast){
			if(dq.empty()){
				ans = false;
				break;
			}
			if(s[j] == dq.back() || (s[j] == '?' && good.count(dq.back()))){
				dq.pop_back();
				j--;
				continue;
			}
			ans = false;
			break;
		}
		while(i == j && !dq.empty()){
			if(good.count(dq.front())){
				ans = false;
				break;
			}
			dq.pop_front();
		}
		if(!dq.empty()) ans = false;
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}
