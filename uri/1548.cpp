#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int m;
    scanf("%d",&m);
    int a[m], ord[m], cont = 0;
    for(int i = 0; i < m; i++) {
      scanf("%d",&a[i]);
      ord[i] = -a[i];
    }
    sort(ord,ord+m);
    for(int i = 0; i < m; i++){
      if(a[i] == -ord[i]) cont++;
    }
    printf("%d\n",cont);
  }
  return 0;
}