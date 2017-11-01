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

int n, m;
vi graph[3010];
ll ans;

ll bin(int x){
	return x * (x - 1) / 2;
}

void bfs(int no){
	map<int,int> chk;
	queue<int> q;
	for(int i = 0; i < graph[no].size(); i++){
		int x = graph[no][i];
		q.push(x);
	}
	while(!q.empty()){
		int a = q.front(); q.pop();
		for(int i = 0; i < graph[a].size(); i++){
			int x = graph[a][i];
			if(x == no) continue;
			chk[x]++;
		}
	}
	map<int,int>::iterator it = chk.begin();
	for(; it != chk.end(); it++){
		if(it->S < 2) continue;
		ans += bin(it->S);
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		graph[a].pb(b);
	}
	for(int i = 1; i <= n; i++) bfs(i);
	printf("%d\n",ans);
	return 0;
}
