#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> Vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  ll m, X = 0, n = 0;
  cin >> m;
  ll canadd[100100];
  for(int i = 1; i <= cbrt((double)m); i++){
    canadd[i] = (((i+1)*(i+1)*(i+1))-1)/(i*i*i);
  }
  for(ll i = 1; i <= cbrt((double)m); i++){
    ll Y = canadd[i]*i*i*i;
    int dif = 0;
    while(X + Y > m && dif < canadd[i]){
      dif++;
      Y = (canadd[i]-dif)*i*i*i;
    }
    if(dif > canadd[i]) break;
    printf("Can place %d of %d\n",(canadd[i]-dif),i);
    X += Y;
    n += canadd[i]-dif;
  }
  cout << n << " " << X << endl;
  return 0;
}
