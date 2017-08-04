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
  int n, x, cont = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    if(x) cont++;
  }
  if(n == 1 && cont) cout << "YES\n";
  else if(n == 1 && !cont) cout << "NO\n";
  else if(cont == n-1) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
