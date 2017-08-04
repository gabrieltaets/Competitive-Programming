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
		int l, m, load = 0, cont = 0;
		queue<int> left, right;
		scanf("%d %d",&l,&m);
		l *= 100;
		for(int i = 0; i < m; i++){
			int size;
			string side;
			cin >> size >> side;
			if(side == "left") left.push(size);
			else right.push(size);
		}
		while(!left.empty() || !right.empty()){
			while(!left.empty() && load + left.front() <= l){
				load += left.front();
				left.pop();
			}
			cont++;
			load = 0;
			if(right.empty() && left.empty()) break;
			while(!right.empty() && load + right.front() <= l){
				load += right.front();
				right.pop();
			}
			cont++;
			load = 0;
		}
		printf("%d\n",cont);
	}
	return 0;
}
