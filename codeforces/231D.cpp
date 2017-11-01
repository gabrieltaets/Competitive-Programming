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

class Point {
  public:
	int x, y, z;
	Point(){};
	Point(int _x, int _y, int _z){
		x = _x; y = _y; z = _z;
	};
};

int main(){
	int x, y, z, fac[10], s = 0;
	scanf("%d %d %d",&x,&y,&z);
	Point pos(x,y,z);
	scanf("%d %d %d",&x,&y,&z);
	Point ops(x,y,z);
	for(int i = 0; i < 6; i++){
		scanf("%d",&fac[i]);
	}
	if(pos.y < 0) s += fac[0];
	if(pos.y > ops.y) s += fac[1];
	if(pos.z < 0) s += fac[2];
	if(pos.z > ops.z) s += fac[3];
	if(pos.x < 0) s += fac[4];
	if(pos.x > ops.x) s += fac[5];
	printf("%d\n",s);
	return 0;
}
