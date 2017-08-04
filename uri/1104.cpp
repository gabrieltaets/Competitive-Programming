#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b;
  vector<int> v(10010);
  while(scanf("%d %d",&a,&b) && (a+b)){
    set<int> x, y;
    int n;
    for(int i = 0; i < a; i++){
      scanf("%d",&n);
      x.insert(n);
    }
    for(int i = 0; i < b; i++){
      scanf("%d",&n);
      y.insert(n);
    }
    vector<int>::iterator it = set_intersection(x.begin(),x.end(),y.begin(),y.end(),v.begin());
    printf("%d\n",min(x.size()-(it-v.begin()),y.size()-(it-v.begin())));
  }
  return 0;
}