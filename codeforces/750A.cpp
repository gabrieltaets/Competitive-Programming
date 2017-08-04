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
  int n, k, cont = 0;
  cin >> n >> k;
  k = 240-k;
  for(int i = 1; i <= n; i++){
    if(5*i <= k){
      cont++;
      k -= 5*i;
    }
  }
  cout << cont << endl;
  return 0;
}
