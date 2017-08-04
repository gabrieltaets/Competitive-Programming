#include <bits/stdc++.h>
using namespace std;
int main(){
  int month[32], week[8], n;
  string str;
  for(int i = 1; i < 30; i++) month[i] = 12;
  month[30] = 11;
  month[31] = 7;
  for(int i = 1; i < 8; i++) week[i] = 52;
  week[5] = week[6] = 53;
  scanf("%d ",&n);
  getline(cin,str);
  if(!str.compare("of week"))
    printf("%d\n",week[n]);
  else printf("%d\n",month[n]);
  return 0;
}