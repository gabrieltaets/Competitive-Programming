#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  for(int c = 1; c <= n; c++){
    string x, b;
    cin >> x >> b;
    printf("Case %d:\n",c);
    if(b == "dec"){
      int y = stoi(x);
      printf("%x hex\n",y);
      int i;
      for(i = 31; i >= 0; i--) if(y&(1<<i)) break;
      for(; i >= 0; i--){
        if(y&(1<<i)) putchar('1');
        else putchar('0');
      }
      printf(" bin\n");
    }
    if(b == "hex"){
      int y = stoi(x,NULL,16);
      printf("%d dec\n",y);
      int i;
      for(i = 31; i >= 0; i--) if(y&(1<<i)) break;
      for(; i >= 0; i--){
        if(y&(1<<i)) putchar('1');
        else putchar('0');
      }
      printf(" bin\n");
    }
    if(b == "bin"){
      int y = stoi(x,NULL,2);
      printf("%d dec\n",y);
      printf("%x hex\n",y);
    }
    printf("\n");
  }
  return 0;
}