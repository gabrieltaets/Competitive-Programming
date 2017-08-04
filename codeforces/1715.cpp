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
  scanf("%d %d",&n,&m);
  bool mat[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d",&mat[i][j]);
    }
  }
  int v[m], cont = 0;
  for(int i = 0; i < m; i++){
    v[i] = 1;
    for(int j = 0; j < n; j++){
      v[i] &= mat[j][i];
    }
    if(v[i]) cont++;
  }
  puts(to_string(cont).c_str());
  return 0;
}
