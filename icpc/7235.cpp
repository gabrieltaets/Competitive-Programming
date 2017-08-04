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
vi primes;
bool isPrime[1010];
void genPrimes(){
  primes.pb(2);
  memset(isPrime,false,sizeof isPrime);
  for(int i = 3; i <= 1000; i+=2){
    int j;
    for(j = 3; j <= (int) sqrt((double)i); j+=2){
      if(i%j == 0) break;
    }
    if(j > (int)sqrt((double)i)) {
      primes.pb(i);
      isPrime[i] = true;
    }
  }
}
bool check(int num){
  int i, j;
  for(i = 0; i < primes.size(); i++){
    if(primes[i] >= num) break;
    for(j = 0; j < primes.size(); j++){
      if(primes[i] + primes[j] >= num) break;
      if(isPrime[num-primes[i]-primes[j]]){
        vi ans;
        ans.pb(primes[i]);
        ans.pb(primes[j]);
        ans.pb(num-primes[i]-primes[j]);
        sort(ans.begin(),ans.end());
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        return true;
      }
    }
  }
  return false;
}

int main(){
  int k, t;
  genPrimes();
  cin >> t;
  while(t--){
    cin >> k;
    if(!check(k)){
      cout << 0 << endl;
    }
  }
  return 0;
}
