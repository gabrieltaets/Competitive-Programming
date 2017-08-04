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
	regex e("(C*)(E*)(S*)");
	int n;
	scanf("%d",&n);
	while(n--){
		string str;
		cin >> str;
		printf("%s\n",regex_match(str,e)?"yes":"no");
	}
	return 0;
}
