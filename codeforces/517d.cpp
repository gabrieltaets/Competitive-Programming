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
double pd[2010][2010];
int main(){
  int n, t;
  double p;
  cin >> n >> p >> t;
  for(int i = 0; i < 2010; i++) for(int j = 0; j < 2010; j++) pd[i][j] = 0;
  pd[0][0] = 1;
  for(int i = 0; i <= t; i++){
    for(int j = 0; j <= n; j++){
      if(j == n) pd[i+1][j] += pd[i][j];
      else {
        pd[i+1][j+1] += pd[i][j] * p;
        pd[i+1][j] += pd[i][j]*(1.0-p);
      }
    }
  }
  double sum = 0;
  for(int i = 0; i <= n; i++){
    sum += pd[t][i]*i;
  }
  printf("%.9f\n",sum);
  return 0;
}
