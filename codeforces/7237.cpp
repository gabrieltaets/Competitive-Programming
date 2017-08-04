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
  int T;
  scanf("%d",&T);
  while(T--){
    int n, m;
    scanf("%d %d",&n,&m);
    int X=0, Y=0;
    for(int i = m-1; i >= 0; i--){
      int a;
      scanf("%d",&a);
      X += a*pow(10.0,(double)i);
    }
    for(int i = m-1; i >= 0; i--){
      int a;
      scanf("%d",&a);
      Y += a*pow(10.0,(double)i);
    }
    int wheel[n], cont = 0;
    for(int i = 0; i < n; i++) scanf("%d",&wheel[i]);
    for(int i = 0; i < n; i++){
      int Z = 0;
      for(int j = 0; j < m; j++){
        int p = (i+j)%n;
        Z += wheel[p]*pow(10.0,(double)m-j-1.0);
      }
      if(Z >= X && Z <= Y) cont++;
    }
    cout << cont << endl;
  }
  return 0;
}
