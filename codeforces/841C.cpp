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

map<int,priority_queue<int, vi, greater<int>> > m;
int a[200010], b[200010], c[200010];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&b[i]);
		c[i] = b[i];
	}
	sort(a,a+n);
	sort(c,c+n);
	for(int i = 0; i < n; i++){
		m[c[i]].push(a[n-i-1]);
	}
	for(int i = 0; i < n; i++){
		printf("%d ",m[b[i]].top());
		m[b[i]].pop();
	}
	return 0;
}
