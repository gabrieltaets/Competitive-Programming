#include <bits/stdc++.h>
#define MAXN 10000000
#define gP(n)(prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n)(prime[n>>6]&=~(1<<((n>>1)&31)))

using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;
vi primes;
unsigned int prime[MAXN / 64];

void sieve(ll upperbound) { 
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
} }

bool isPrime(ll N) { 
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true; 
}

long long power(int b, int p){
  if(!p) return 1LL;
  long long ans = power(b,p/2);
  ans *= ans;
  if(p%2) ans *= b;
  return ans;
}

int main(){
  int n;
  cin >> n;
  sieve(n+1);
  vector<int> ans;
  for(int i = 0; i < (int) primes.size(); i++){
    if(primes[i] > n) break;
    for(int k = 1; power(primes[i],k) <= n; ans.push_back(power(primes[i],k++)));
  }
  printf("%d\n",(int)ans.size());
  for(int i = 0; i < (int)ans.size(); i++){
    printf("%d ",ans[i]);
  }
  return 0;
}
