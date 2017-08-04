#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

ll pd[150][150];
ll bin[150][150];

template <typename T>
T extGcd(T a, T b, T& x, T& y){
  if(b == 0){
    x = 1;
    y = 0;
    return a;
  }
  else {
    int g = extGcd(b,a%b,y,x);
    y -= a/b*x;
    return g;
  }
}
template <typename T>
T modInv(T a, T m){
  T x, y;
  extGcd(a,m,x,y);
  return(x%m+m)%m;
}

void binomial(int n){
  ll fat[150];
  fat[0] = 1;
  for(int i = 1; i < n; i++) fat[i] = (i * fat[i-1])%1000000007LL;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      bin[i][j] = fat[i]*modInv((fat[j]*fat[i-j]),1000000007LL);
    }
  }
}

ll solve(int n, int k){
  if(pd[n][k] != -1) return pd[n][k];
  if(n <= 2) return 1;
  if(k == 1) return 0;
  ll sum = 0;
  for(int i = 1; i < n; i++){
    sum += (solve(n-i,k-1)%1000000007)*(solve(i-1,k-1)%1000000007)*i*bin[n-1][i-1];
    sum %= 1000000007;
  }
  pd[n][k] = sum;
  //printf("pd(%d,%d) = %d\n",n,k,sum);
  return sum;
}

int main(){
  int n, K;
  cin >> n >> K;
  memset(pd,-1,sizeof pd);
  binomial(n);
  cout << solve(n,K) << endl;
  return 0;
}
