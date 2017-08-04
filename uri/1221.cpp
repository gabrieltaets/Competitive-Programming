#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll _sieve_size;
bitset<10000010> bs;
vi primes;

void crivo(ll upperbound) {
  upperbound = (ll) sqrt((double)upperbound);
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i)
      bs[j] = 0;
    primes.push_back((int)i);
} }

bool primo(ll N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
  if (N % primes[i] == 0) return false;
  return true;
}

int main(){
  int N;
  scanf("%d",&N);
  crivo(10000000000LL);
  while(N--){
    int x;
    scanf("%d",&x);
    if(primo((ll)x)) printf("Prime\n");
    else printf("Not Prime\n");
  }
  return 0;
}