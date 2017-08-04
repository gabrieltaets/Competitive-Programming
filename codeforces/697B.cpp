#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int a, b, szd;
  char d[1000];
  scanf("%d.%[^e]e%d",&a,d,&b);
  szd = strlen(d);
  if(b == 0){
    printf("%d",a);
    if(szd > 1 || d[0] != '0'){
      printf(".%s",d);
    }
    printf("\n");
  }
  else {
    int i;
    bool flag = false;
    printf("%d",a);
    for(i = szd; i < b; i++){
      d[i] = '0';
    }
    d[i] = '\0';
    szd = strlen(d);
    for(i = 0; i < b; i++){
      putchar(d[i]);
    }
    for(i = b; i < szd; i++){
      if(d[i] != '0') flag = true;
    }
    
    if(flag) {
      for(i = szd-1; i >= 0; i--){
        if(d[i] != '0'){
          d[i+1] = '\0';
          break;
        }
      }
      printf(".%s",d+b);
    }
    printf("\n");
  }
  return 0;
}
