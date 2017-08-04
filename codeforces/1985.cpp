#include <bits/stdc++.h>
using namespace std;
int main(){
  double v[] = {1.5, 2.5, 3.5, 4.5, 5.5};
  int p;
  double sum = 0;
  scanf("%d",&p);
  for(int i = 0; i < p; i++){
    int c, q;
    scanf("%d %d",&c,&q);
    sum += v[c-1001]*q;
  }
  printf("%.2f\n",sum);
  return 0;
}