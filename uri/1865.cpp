#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    string nome;
    int forca;
    cin >> nome >> forca;
    if(nome == "Thor") printf("Y\n");
    else printf("N\n");
  }
  return 0;
}