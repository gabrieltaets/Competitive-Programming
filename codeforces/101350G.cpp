/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

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

bool allowed[200];
int main(){
	allowed['A'] = 1;
	allowed['H'] = 1;
	allowed['I'] = 1;
	allowed['M'] = 1;
	allowed['O'] = 1;
	allowed['T'] = 1;
	allowed['U'] = 1;
	allowed['V'] = 1;
	allowed['W'] = 1;
	allowed['X'] = 1;
	allowed['Y'] = 1;
	int T;
	scanf("%d",&T);
	while(T--){
		string s;
		cin >> s;
		bool ans = true;
		for(int i = 0; i <= s.size()/2; i++){
			int m = s.size() - i - 1;
			if(!allowed[s[i]] || s[i] != s[m]){
				ans = false;
				break;
			}
		}
		printf("%s\n",ans?"yes":"no");
	}
	return 0;
}
