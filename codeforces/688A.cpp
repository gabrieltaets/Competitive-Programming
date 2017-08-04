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
  int n, d;
  cin >> n >> d;
  char res[105];
  for(int i = 0; i <= 100; i++) res[i] = 1;
  for(int i = 0; i < d; i++){
    for(int j = 0; j < n; j++){
      char c;
      scanf(" %c",&c);
      c -= '0';
      res[i] &= c;
    }
  }
  int m = 0, cont = 0;
  for(int i = 0; i < d; i++){
    if(!res[i]) cont++;
    else cont = 0;
    m = max(m,cont);
  }
  cout << m << endl;
  return 0;
}
