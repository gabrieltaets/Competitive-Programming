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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, m, p;
string team[205];
map<string,int> number;
int lead = 0, last = 0, ans = 0;
int score[205], penalty[205];
int wa[205][15];

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++){
		cin >> team[i];
		number[team[i]] = i;
	}
	for(int i = 0; i < m; i++){
		string t, verd;
		char prob;
		int time;
		cin >> t >> prob >> time >> verd;
		int nt = number[t];
		if(verd == "NO"){
			wa[nt][prob-'A']++;
			continue;
		}
		score[nt]++;
		penalty[nt] += 20*wa[nt][prob-'A'] + time;
		if(score[nt] > score[lead] || (score[nt] == score[lead] && (penalty[nt] < penalty[lead] || (penalty[nt] == penalty[lead] && nt == 0)))){
			if(lead == 0) ans += time - last;
			lead = nt;
			if(nt == 0) last = time;
		}
	}
	if(lead == 0) ans += 300 - last;
	printf("%d\n",ans);
	return 0;
}
