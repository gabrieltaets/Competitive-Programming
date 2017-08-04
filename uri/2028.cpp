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
  int n, c = 1;
  while(scanf("%d",&n)!=EOF){
    int x = 1+n*(1+n)/2;
    printf("Caso %d: %d numer%s\n",c++,x,x==1?"o":"os");
    printf("0");
    for(int i = 1; i <= n; i++){
      for(int j = 0; j < i; j++){
        printf(" %d",i);
      }
    }
    printf("\n\n");
  }  
  return 0;
}
