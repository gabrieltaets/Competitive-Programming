#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  for(int c = 1; c <= n; c++){
    string s, r;
    cin >> s >> r;
    printf("Caso #%d: ",c);
    if(s == r) printf("De novo!\n");
    else if(s == "tesoura" && (r == "papel" || r == "lagarto"))
      printf("Bazinga!\n");
    else if(s == "papel" && (r == "pedra" || r == "Spock"))
      printf("Bazinga!\n");
    else if(s == "pedra" && (r == "lagarto" || r == "tesoura"))
      printf("Bazinga!\n");
    else if(s == "lagarto" && (r == "Spock" || r == "papel"))
      printf("Bazinga!\n");
    else if(s == "Spock" && (r == "tesoura" || r == "pedra"))
      printf("Bazinga!\n");
    else printf("Raj trapaceou!\n");
  }
  return 0;
}