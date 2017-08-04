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

double grafo[110][110];
int n, m;

void floyd_warshall(){
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        grafo[i][j] = max(grafo[i][j],grafo[i][k]*grafo[k][j]);
      }
    }
  }
}

int main(){
  while(scanf("%d",&n)!=EOF && n){
    scanf("%d",&m);
    memset(grafo,0,sizeof grafo);
    for(int i = 0; i < n; i++) grafo[i][i] = 1;
    for(int i = 0; i < m; i++){
      int a, b, p;
      scanf("%d %d %d",&a,&b,&p);
      a--; b--;
      grafo[a][b] = grafo[b][a] = p/100.0;
    }
    floyd_warshall();
    printf("%.6lf percent\n",grafo[0][n-1]*100);
  }
  return 0;
}
