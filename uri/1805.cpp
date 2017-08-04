#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  ll a, b, res;
  cin >> a >> b;
  res = (a+b)*(b-a+1LL)/2LL;
  cout << res << endl;
  return 0;
}