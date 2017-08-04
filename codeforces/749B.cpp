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

int main(){
  ii p[3];
  for(int i = 0; i < 3; i++){
    cin >> p[i].F >> p[i].S;
  }
  sort(p,p+3);
  ii v1(p[0].F+p[2].F-p[1].F,p[0].S+p[2].S-p[1].S);
  ii v2(p[0].F+p[1].F-p[2].F,p[0].S+p[1].S-p[2].S);
  ii v3(p[1].F+p[2].F-p[0].F,p[1].S+p[2].S-p[0].S);
  printf("3\n");
  printf("%d %d\n",v1.F,v1.S);
  printf("%d %d\n",v2.F,v2.S);
  printf("%d %d\n",v3.F,v3.S);
 
  return 0;
}
