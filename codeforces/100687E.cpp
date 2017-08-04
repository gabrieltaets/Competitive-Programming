#include <bits/stdc++.h>
using namespace std;
int main(){
  string str1, str2;
  cin >> str1;
  cin >> str2;
  int cont = 0;
  for(int i = 0; i < str1.size(); i++)
    if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i]==tolower(str2[i])) cont++;
  if(cont <= 3) printf("Remove\n");
  else printf("Kafo\n");
  return 0;
}