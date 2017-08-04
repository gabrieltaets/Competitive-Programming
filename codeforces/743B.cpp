#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define MSB(x) 63-__builtin_clzll(x)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
  int n;
  ll k;
  cin >> n >> k;
  if(k & 1LL){
    cout << 1 << endl;
    return 0;
  }
  int ans = -1;
  while(k-(1LL<<MSB(k)) != 0){
    k -= (1LL<<MSB(k));
  }
  cout << (int) MSB(k)+1 << endl;
	return 0;
}
