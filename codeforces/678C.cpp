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

ll gcd(ll a, ll b){
  if(!b) return abs(a);
  return gcd(b,a%b);
}

ll lcm(ll a, ll b){
  if(a && b) return abs(a) / gcd(a,b) * abs(b);
  return abs(a|b);
}


int main(){
  ll n, a, b, q, p;
  cin >> n >> a >> b >> p >> q;
  ll qc = n/lcm(a,b);
  ll qa = n/a-qc, qb = n/b-qc;
  ll sum = qa*p+qb*q+max(qc*q,qc*p);
  cout << sum << endl;
  return 0;
}
