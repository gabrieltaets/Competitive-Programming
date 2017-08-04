#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, Q, c = 1;
  while(scanf("%d %d",&N,&Q) && (N+Q)){
    vector<int> m(N);
    for(int i = 0; i < N; i++){
      scanf("%d",&m[i]);
    }
    sort(m.begin(),m.end());
    printf("CASE# %d:\n",c++);
    int x;
    for(int i = 0; i < Q; i++){
      scanf("%d",&x);
      vector<int>::iterator it = lower_bound(m.begin(),m.end(),x);
      if(it == m.end() || *it != x) printf("%d not found\n",x);
      else {
        it++;
        printf("%d found at %d\n",x,it-m.begin());
      }
    }
  }  
  return 0;
}
