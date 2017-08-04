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
  int t, x, s;
  cin >> t >> s >> x;
  int r1 = (x-t)/s, r2 = (x-t-1)/s;
  if(x < t) printf("NO\n");
  else if(t == x || r1*s+t == x) printf("YES\n");
  else {
    if(r2 && r2*s+t+1 == x) printf("YES\n");
    else printf("NO\n");  
  }
  return 0;
}
