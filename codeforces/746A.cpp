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
  int a, b, c;
  cin >> a >> b >> c;
  int x = min(a, min(b/2,c/4));
  x += 2*x + 4*x;
  cout << x << endl;
	return 0;
}
