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
  int n, m;
  cin >> n >> m;
  ll qn[11], qm[11];
  for(int i = 0; i <= 10; i++){
    qn[i] = qm[i] = 0;
  }
  for(int i = 1; i <= n; i++){
    qn[i%10]++;
  }
  for(int i = 1; i <= m; i++){
    qm[i%10]++;
  }
  qn[10] = qn[0];
  qm[10] = qm[0];
  ll pairs = 0;
  for(int i = 0; i < 10; i++){
    pairs += qn[i]*qm[10-i] + qn[i]*qm[(i>5?15-i:5-i)   ];
  }
  cout << pairs << endl;
  return 0;
}
