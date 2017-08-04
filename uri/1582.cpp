#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
inline int gcd (int a, int b) {
  return b ? gcd(b, a % b) : abs(a);
}

int main(){
  int v[3];
  while(cin >> v[0] >> v[1] >> v[2]){
    sort(v,v+3);
    printf("tripla");
    if(v[0]*v[0]+v[1]*v[1]==v[2]*v[2]) {
      printf(" pitagorica");
      if(gcd(v[0],gcd(v[1],v[2])) == 1) printf(" primitiva");
    }
    printf("\n");  
  }
  return 0;
}