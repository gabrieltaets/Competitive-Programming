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
  ll x, y, num;
  cin >> x >> y;
  num = ceil((double)y/(y-x));
  if(num <= 1) num = 2;
  cout << num << endl;
  return 0;
}
