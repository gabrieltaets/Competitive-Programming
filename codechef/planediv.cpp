#include <bits/stdc++.h>
using namespace std;

inline int gcd (int a, int b) {
	return b ? gcd(b, a % b) : abs(a);
}

typedef struct stLine {
	int up, down;
	bool operator< (struct stLine l) const {
		if((double)up/down == (double)l.up/l.down){
			if(up < l.up) return true;
			else if(up > l.up) return false;
			else return down < l.down;
		}
		return (double)up/down < (double)l.up/l.down;
	}
} Line;

int main(){
	long long int T;
	cin >> T;
	while(T--){
		int N, A, B, C, mset = 0, g;
		long long nc;
		Line x;
		cin >> N;
		map <Line,int> m;
		pair <map <Line,int>::iterator,bool> p;
		set <pair<Line,int> > chk;
		pair <set<pair<Line,int> >::iterator,bool> p2;
		for(int i = 0; i < N; i++){
			scanf("%d %d %d",&A,&B,&C);
			g = gcd(A,gcd(B,C));
			x.up = A/g; x.down = B/g; C /= g;
			
			p2 = chk.insert(make_pair(x,C));
			if(!p2.second) continue;
			//printf("Inserindo %d %d %d\n",x.up,x.down,C);
			p = m.insert(make_pair(x,1));
			if(!p.second) p.first->second++;
			mset = max(mset,p.first->second);
		}
		printf("%d\n",mset);
	}
	return 0;
}