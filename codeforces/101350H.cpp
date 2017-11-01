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
int valid[1010][1010];
bool memo1[1010][1010];
string s;

int checkPalindrome(int l, int r){
	//printf("At (%d, %d)\n",l,r);
	if(l > r) return 0;
	if(memo1[l][r]) {
		//printf("already known %d\n",valid[l][r]);
		return valid[l][r];
	}
	memo1[l][r] = 1;

	if(l == r) {
		//printf("returning s[%d] (%c) = %d\n",r,s[r],allowed[s[r]]);
		return valid[l][r] = allowed[s[r]];
	}
	if(l == r-1) return valid[l][r] = (s[l] == s[r] && allowed[s[l]] && allowed[s[r]]);
	return valid[l][r] = (checkPalindrome(l+1, r-1) && s[l] == s[r] && allowed[s[l]] && allowed[s[r]]);
}

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
		cin >> s;
		int ans = 0;
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; j < s.size(); j++){
				memo1[i][j] = valid[i][j] = 0;
			}
		}
		for(int i = 0; i < s.size(); i++){
			for(int j = i; j < s.size(); j++){
				//printf("Checking [%d, %d] (%s)\n",i,j,s.substr(i,j-i+1).c_str());
				if(checkPalindrome(i,j)){
					//printf("Palindrome\n");
					ans = max(ans, j-i+1);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
