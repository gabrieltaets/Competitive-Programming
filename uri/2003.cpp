#include <bits/stdc++.h>
using namespace std;
int main(){
  int h, m;
  while(scanf("%d:%d",&h,&m) != EOF){
    h -= 8;
    m += h*60+60;
    printf("Atraso maximo: %d\n",m > 0 ? m : 0);
  }
  return 0;
}
