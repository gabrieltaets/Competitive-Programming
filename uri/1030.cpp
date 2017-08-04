#include <bits/stdc++.h>
using namespace std;

int Josephus(int n, int k){
  if(k == 1)return n-1;
  if(k == 2){
    int j = floor(log10(n)/log10(2.0));
    n &= ~(1<<j);
    n = n<<1;
    n|=1;
    return n-1;
  }
  if(n==1) return 0;
  return (Josephus(n-1,k)+k)%n;
}

int main(){
  int NC;
  scanf("%d",&NC);
  for(int c = 1; c<=NC; c++){
    int n, k;
    scanf("%d %d",&n,&k);
    printf("Case %d: %d\n",c,Josephus(n,k)+1);
  }
  return 0;
}