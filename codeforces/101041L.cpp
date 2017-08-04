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
int main(){
  double l, c, a, b, x, e, pi = 3.14169, g = 9.80665;
  cin >> c >> l;
  a = max(l,c);
  b = min(l,c);
  e = sqrt(a*a-b*b)/a;
  x = pi*a*(2.0-e*e/2.0-3.0*e*e*e*e/32.0-5*e*e*e*e*e*e/128.0)/4.0;
  printf("%.6f\n",x);
  double t = sqrt(2.0*g*l);
  printf("%.6f\n",t);
  return 0;
}

