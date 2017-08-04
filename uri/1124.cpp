#include <bits/stdc++.h>
using namespace std;
int main(){
  int l, c, r1, r2;
  while(scanf("%d %d %d %d",&l,&c,&r1,&r2)!=EOF && l+c+r1+r2){
    if(c > l) swap(c,l);
    if(r2 > r1) swap(r1,r2);
    double d = sqrt((double)l*l+c*c);
    double req = sqrt(2.0)*r1+r1+sqrt(2.0)*r2+r2;
    if(d >= req) cout << "S" << endl;
    else cout << "N\n";
  }
  return 0;
}
