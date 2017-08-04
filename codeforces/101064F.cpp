#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int Josephus(int n, int k){
  if(k == 1) return n-1;
  if(k == 2) {
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
  int T;
  scanf("%d",&T);
  while(T--){
    int N, i;
    scanf("%d %d",&N,&i);
    int ans = 0;
    bool even = 0;
    if(i%2==0) while(i%2==0 && !even || i%2 && even) {
      //printf("N = %d i = %d even = %d\n",N,i,even);
      if(even){
        if(N%2) even = !even;
        ans += (int) floor(N/2.0);
        N = (int) ceil(N/2.0);
        i = (int) floor((i-1)/2.0)+1;
      }
      else {
        if(N%2) even = !even;
        ans += (int) ceil(N/2.0);
        N = (int) floor(N/2.0);
        i = (int) floor((i-1)/2.0)+1;
      }
    }
    ans += (int) ceil(i/2.0);
    printf("%d\n",ans);
  }
  return 0;
}
