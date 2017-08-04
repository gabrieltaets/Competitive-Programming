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
bitset<1000010> bs;
vi primos;
int acm[1000010];
void crivo(){
  primos.pb(2);
  for(ll i = 3; i <= 1000000; i+=2){
    if(bs[i]) continue;
    for(ll j = i*i; j <= 1000000; j += i){
      bs[j] = 1;
    }
    //printf("Found %d is prime\n",i);
    primos.pb(i);
  }
  printf("Found %d primes\n",primos.size());
  for(int i = 1; i < primos.size(); i++){
    if(primos[i]-primos[i-1] == 2) {
      acm[primos[i]]+=2;
      if(i > 1 && primos[i-1]-primos[i-2]==2) acm[primos[i]]--;
    }
  }
  for(int i = 1; i <= 1000000; i++){
    acm[i] += acm[i-1];
  }
}
int main(){
  crivo();
  int q;
  scanf("%d",&q);
  while(q--){
    int a, b;
    scanf("%d %d",&a,&b);
    printf("%d\n",acm[b]-acm[a-1]);
  }
  return 0;
}
