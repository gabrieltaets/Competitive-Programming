#include <bits/stdc++.h>
using namespace std;
int main(){
  int D, VF, VG;
  while(scanf("%d %d %d",&D,&VF,&VG)!=EOF){
    double DG = sqrt(144.0+D*D);
    if(DG/VG <= 12.0/VF) printf("S\n");
    else printf("N\n"); 
  }
  return 0;
}