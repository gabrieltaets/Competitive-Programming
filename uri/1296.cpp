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
  double m[3];
  while(scanf("%lf %lf %lf",m,m+1,m+2)!=EOF){
    double sp = (m[0]+m[1]+m[2])/2.0;
    sort(m,m+3);
    if(m[0] + m[1] <= m[2]) printf("%.3lf\n",-1.0);
    else printf("%.3lf\n",4.0/3.0*sqrt(sp*(sp-m[0])*(sp-m[1])*(sp-m[2])));
  }
  return 0;
}
