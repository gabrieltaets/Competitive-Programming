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
	int a, b, c, d;
	cin >> d >> b >> c >> a;
	int e, f;
	e = (a & b) | (c ^ d);
	f = (c | b) ^ (d & a);/*
	for(a = 0; a < 2; a++){
		for(b = 0; b < 2; b++){
			for(c = 0; c < 2; c++){
				for(d = 0; d < 2; d++){
					if((e|f)){
						printf("%d %d %d %d\n",a,b,c,d);
					}
				}
			}
		}
	}*/
	printf("%d\n",(e&f));
	return 0;
}
