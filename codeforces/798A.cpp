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
	int dif = 0;
	cin >> s;
	for(int i = 0; i < s.size()/2; i++){
		int j = s.size()-i-1;
		if(s[i] != s[j]) dif++;
	}
	printf("%s\n",((s.size()%2==1 && dif <= 1) || (dif==1))?"YES":"NO");
	return 0;
}
