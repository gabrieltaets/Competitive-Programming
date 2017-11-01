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

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		string s, t;
		cin >> s >> t;
		map<char, int> q1, q2;
		for(int i = 0; i < s.size(); i++) q1[s[i]]++;
		for(int i = 0; i < t.size(); i++) q2[t[i]]++;
		pair<char, int> best(0,0);
		for(int i = 0; i < s.size(); i++){
			if(q2[s[i]] == 0 && best.S <= q1[s[i]]){
				best = mp(s[i], q1[s[i]]);
			}
		}
		if(best.S == 0) {
			printf("B\n");
			continue;
		}
		if(best.S > 1){
			printf("A\n");
			continue;
		}
		best = mp(0,0);
		for(int i = 0; i < t.size(); i++){
			if(q1[t[i]] == 0 && best.S <= q2[t[i]]){
				best = mp(t[i], q2[t[i]]);
			}
		}
		if(best.S == 0) printf("A\n");
		else printf("B\n");
	}
	return 0;
}
