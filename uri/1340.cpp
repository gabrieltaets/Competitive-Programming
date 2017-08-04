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
	while(scanf("%d",&n)!=EOF){
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		int qtd = 0;
		bool isQueue = true, isStack = true, isPQ = true;
		for(int i = 0; i < n; i++){
			int cho, x, y;
			scanf("%d %d",&cho,&x);
			if(cho == 1){
				q.push(x);
				s.push(x);
				pq.push(x);
			}
			else {
				y = q.front();
				q.pop();
				if(y != x) isQueue = false;
				y = s.top();
				s.pop();
				if(y != x) isStack = false;
				y = pq.top();
				pq.pop();
				if(y != x) isPQ = false;
			}
		}
		qtd = isQueue + isStack + isPQ;
		if(qtd > 1) printf("not sure\n");
		else if(qtd == 0) printf("impossible\n");
		else if(isQueue) printf("queue\n");
		else if(isStack) printf("stack\n");
		else printf("priority queue\n");
	}
	return 0;
}
