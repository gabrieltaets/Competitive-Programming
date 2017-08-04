#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int a = 0, d = 0;
	for(int i = 0; i < n; i++){
		if(str[i] == 'A') a++;
		else d++;
	}
	printf("%s\n",a==d?"Friendship":(a>d?"Anton":"Danik"));
	return 0;
}
