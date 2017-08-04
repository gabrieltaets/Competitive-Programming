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
	int n, m;
	while(scanf("%d %d",&n,&m)!=EOF && (n|m)){
		queue<ii> q;
		q.push(mp(0,1));
		bool solved = false;
		while(!q.empty() && !solved){
			int at = q.front().F;
			int i = q.front().S;
			int jmp = 2*i-1;
			q.pop();
			if(at == m) solved = true;
			if(at-jmp > 0) q.push(mp(at-jmp,i+1));
			if(at+jmp < n) q.push(mp(at+jmp,i+1));
		}
		printf("%s\n",solved?"Let me try!":"Don't make fun of me!");
	}
	return 0;
}
