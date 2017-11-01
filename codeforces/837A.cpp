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
	int n;
	scanf("%d",&n);
	getchar();
	string str;
	getline(cin, str);
	int vw = 0, vt = 0;
	for(int i = 0; i < n; i++){
		if(str[i] == ' '){
			vt = max(vt, vw);
			vw = 0;
			continue;
		}
		if(str[i] < 'a') vw++;
	}
	vt = max(vt, vw);
	printf("%d\n",vt);
	return 0;
}
