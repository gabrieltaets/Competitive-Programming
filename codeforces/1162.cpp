#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int l;
    scanf("%d",&l);
    int v[l], cont = 0;
    for(int i = 0; i < l; i++){
      scanf("%d",&v[i]);
    }
    for(int i = l-1; i >= 0; i--){
      for(int j = 0; j < i; j++){
        if(v[j] > v[j+1]){
          swap(v[j],v[j+1]);
          cont++;
        }
      }
    }
    printf("Optimal train swapping takes %d swaps.\n",cont);
  }
  return 0;
}