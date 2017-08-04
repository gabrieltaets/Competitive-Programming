#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  double sum = 0, spt, kgs = 0;
  for(int i = 0; i < n; i++){
    int kg = 1;
    scanf("%lf",&spt);
    getchar();
    string str;
    getline(cin,str);
    for(int j = 0; j < str.size(); j++) if(str[j] == ' ') kg++;
    kgs += kg;
    sum += spt;
    printf("day %d: %d kg\n",i+1,kg);
  }
  printf("%.2f kg by day\n",kgs/n);
  printf("R$ %.2f by day\n",sum/n);
  return 0;
}