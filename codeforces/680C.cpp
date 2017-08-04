#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  vi primes;
  primes.pb(2);
  primes.pb(3);
  primes.pb(5);
  primes.pb(7);
  primes.pb(11);
  primes.pb(13);
  primes.pb(17);
  primes.pb(19);
  primes.pb(23);
  primes.pb(29);
  primes.pb(31);
  primes.pb(37);
  primes.pb(41);
  primes.pb(43);
  primes.pb(47);
  primes.pb(53);
  int i, cont = 0, q = 0, div;
  for(i = 0; i < primes.size(); i++){
    printf("%d\n",primes[i]);
    q++;
    fflush(stdout);
    string str;
    cin >> str;
    if(str == "yes"){
      cont++;
      if(cont > 1){
        printf("composite\n");
        return 0;
      }
      if(primes[i] <= 10){
        printf("%d\n",primes[i]*primes[i]);
        q++;
        fflush(stdout);
        cin >> str;
        if(str == "yes"){
          printf("composite\n");
          return 0;
        }
      }
    }
    if(cont > 1){
      printf("composite\n");
      return 0;
    }
  }
  printf("prime\n");
  return 0;
}
