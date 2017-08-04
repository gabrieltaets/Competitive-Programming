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
  int n, a, b;
  cin >> n;
  b = sqrt(n);
  if(b*b == n){
    printf("%d %d\n",b,b);
    return 0;
  }
  for(b++; b <= n; b++){
    a = n/b;
    if(a*b == n){
      printf("%d %d\n",a,b);
      return 0;
    }
  }
	return 0;
}
