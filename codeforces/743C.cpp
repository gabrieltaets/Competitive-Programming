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
  int n;
  cin >> n;
  ll x, y, z;
  x = n;
  y = n+1;
  z = x*y;
  if(n*(x*y+x*z+y*z) == 2*x*y*z){
    cout << x << " " << y << " " << z << endl;
  }
  else cout << -1 << endl;
	return 0;
}
