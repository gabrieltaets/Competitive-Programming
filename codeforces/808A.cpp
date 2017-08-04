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
	int x;
	cin >> x;
	x++;
	string n = to_string(x);
	int p = 0, cont = 1;
	for(int i = n.size()-1; i > 0; i--){
		if(n[i] != '0'){
			cont += ('0'+10-n[i])*ceil(pow(10,p));
			n[i-1]++;
		}
		p++;
	}
	cout << cont << endl;
	return 0;
}
