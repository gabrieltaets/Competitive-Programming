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
  cin >> n;
  if(n == 1 || n == 2) printf("-1\n");
  else {
    ll a, b;
    if(n%2){ //if odd
      a = (n*n-1)/2;
      b = (n*n+1)/2;
    }
    else {
      a = (n/2)*(n/2)-1;
      b = (n/2)*(n/2)+1;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
