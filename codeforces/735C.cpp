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


int main(){
  ll n;
  int cont = 0;
  cin >> n;
  pair<ll,ll> p = {n,0};
  while(p.F + p.S > 1) {
    //printf("%lld play %d, %lld play %d\n",p.F,cont,p.S,cont-1);
    cont++;
    if((p.F+p.S)&1LL) {
      p.F = (p.F+p.S)/2;
      p.S = 1;
    }
    else {
      p.F = (p.F+p.S)/2;
      p.S = 0;
    }
  }
  cout << cont << endl;
	return 0;
}
