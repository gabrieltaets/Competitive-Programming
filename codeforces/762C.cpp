#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MAXN 100000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string a, b;
int p[MAXN+35], s[MAXN+35];

int main(){
	cin >> a >> b;
	int i, j = 0;
	for(i = 0; i < b.size(); i++){
		for(; j < a.size(); j++){
			if(b[i] == a[j]) {
				p[i+1] = j+1;
				break;
			}
		}
		if(j >= a.size()) p[i+1] = INF;
	}
	j = 0;
	for(i = b.size()-1; i >= 0; i--){
		for(; j < a.size(); j++){
			int pos = a.size()-j-1;
			if(b[i] == a[pos]){
				s[i+1] = j+1;
				break;
			}
		}
		if(j >= a.size()) s[i+1] = INF;
	}
	i = 1; j = a.size();
	while(p[i] + s[j] > a.size()){
		j--;
		if(j == 0) break;
	}
	while(p[i] + s[j] <= a.size()){
		i++;
		if(i == b.size()) break;
	}
	i--;
	if(p[i] + s[j] <= a.size() && (i || j))
		cout << b.substr(0,i) + b.substr(b.size()-j) << endl;
	else cout << "-" << endl;
	return 0;
}
