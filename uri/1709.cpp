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
  int pos = 1, cont = 0;
  do {
    if(pos <= n/2){
      pos *= 2;
    }
    else {
      pos -= (n+1-pos);
    }
    cont++;
  } while(pos != 1);
  cout << cont << endl;
  return 0;
}
