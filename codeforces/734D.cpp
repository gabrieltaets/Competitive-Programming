#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int x, y, n;
int d[3][3];

void checkCheck(char p, int px, int py){
	if(px == x){
		if(p == 'R' || p == 'Q'){
			if(py > y){
				d[0][1] = min(d[0][1],py-y);
			}
			else {
				d[2][1] = min(d[2][1],y-py);
			}
		}
	}
	else if(py == y){
		if(p == 'R' || p == 'Q'){
			if(px > x){
				d[1][2] = min(d[1][2],px-x);
			}
			else {
				d[1][0] = min(d[1][0],x-px);
			}
		}
	}
	else if(abs(px-x) == abs(py-y)){
		if(p == 'B' || p == 'Q'){
			if(px > x && py > y){
				d[0][2] = min(d[0][2], px-x);
			}
			else if(px > x && py < y){
				d[2][2] = min(d[2][2], px-x);
			}
			else if(px < x && py > y){
				d[0][0] = min(d[0][0], x-px);
			}
			else if(px < x && py < y){
				d[2][0] = min(d[2][0], x-px);
			}
		}
	}
}

void checkUncheck(char p, int px, int py){
	if(px == x){
		if(py > y){
			if(py-y < d[0][1]){
				d[0][1] = 2*INF;
			}
		}
		else if(py < y){
			if(y-py < d[2][1]){
				d[2][1] = 2*INF;
			}
		}
	}
	else if(py == y){
		if(px > x){
			if(px-x < d[1][2]){
				d[1][2] = 2*INF;
			}
		}
		else if(px < x){
			if(x-px < d[1][0]){
				d[1][0] = 2*INF;
			}
		}
	}
	else if(abs(py-y)==abs(px-x)){
		if(px>x && py>y){
			if(px-x < d[0][2]){
				d[0][2] = 2*INF;
			}
		}
		else if(px>x && py<y){
			if(px-x < d[2][2]){
				d[2][2] = 2*INF;
			}
		}
		else if(px<x && py>y){
			if(x-px < d[0][0]){
				d[0][0] = 2*INF;
			}
		}
		else if(px<x && py<y){
			if(x-px < d[2][0]){
				d[2][0] = 2*INF;
			}
		}
	}
}

bool ans(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == 1 && j == 1) continue;
			if(d[i][j] != 2*INF) return true;
		}
	}
	return false;
}

int main(){
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) d[i][j] = 2*INF;
	scanf("%d",&n);
	scanf("%d %d",&x,&y);
	vector<pair<char,ii> > pieces;
	for(int i = 0; i < n; i++){
		char p;
		int px, py;
		scanf(" %c %d %d",&p,&px,&py);
		checkCheck(p,px,py);
		pieces.pb({p,{px,py}});
	}
	for(int i = 0; i < n; i++){
		checkUncheck(pieces[i].F,pieces[i].S.F, pieces[i].S.S);
	}
	printf("%s\n",ans()?"YES":"NO");
	return 0;
}
