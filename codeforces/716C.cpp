#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

inline ull gcd (ll a, ll b) {
  return b ? gcd(b, a % b) : abs(a);
}
inline ull lcm(ll a, ll b) {
  if (a && b) return abs(a) / gcd(a, b) * (ll) abs(b);
  return (ll) abs(a | b);
}

int main(){
  int n;
  cin >> n;
  ull k = 1, t = n+1, m = 2;
  while(k != t){
    ull x = lcm(k,k+1);
    ull q = x/k*x-m/k;
    cout << q << endl;
    k++;
    m = x;
  }  
  return 0;
}
