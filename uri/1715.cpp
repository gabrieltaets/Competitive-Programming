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
  int n, m;
  while(scanf("%d %d",&n,&m)!=EOF){
    bool mat[n][m];
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        int x;
        scanf("%d",&x);
        mat[i][j] = x;
      }
    }
    int v, cont = 0;
    for(int i = 0; i < n; i++){
      v = 1;
      for(int j = 0; j < m; j++){
        v &= mat[i][j];
      }
      if(v) cont++;
    }
    cout << cont << endl;
  }
  return 0;
}
