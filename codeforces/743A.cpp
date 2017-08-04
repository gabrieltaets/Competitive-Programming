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
  int a, b, n;
  cin >> n >> a >> b;
  string air;
  cin >> air;
  a--; b--;
  if(air[a] == air[b]) cout << 0 << endl;
  else cout << 1 << endl;
	return 0;
}
