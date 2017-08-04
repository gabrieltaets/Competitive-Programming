#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define A 1234567
#define B 123456
#define C 1234
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int n;
  cin >> n;
  int modA = (int)ceil((double)n/A), modB;
  bool flag = false;
  for(int i = 0; i <= modA && !flag; i++){
    int m = n - i*A;
    modB = (int)ceil((double)m/B);
    for(int j = 0; j <= modB && !flag; j++){
      int k = m - j*B;
      if(k%C == 0) {
        //printf("%d %d %d\n",i,j,k/C);
        if(i >= 0 && j >= 0 && (k/C) >= 0) flag = true;
      }
    }
  }
  if(flag) printf("YES\n");
  else printf("NO\n");
  return 0;
}
