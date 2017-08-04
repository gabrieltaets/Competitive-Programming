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

int n, m;
int grafo[110][110];

void floyd_warshall(){
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(i == j) continue;
        grafo[i][j] = min(grafo[i][j],max(grafo[i][k],grafo[k][j]));
      }
    }
  }
}

int main(){
  int caso = 1;
  while(scanf("%d %d",&n,&m)!=EOF && (n||m)){
    memset(grafo,INF,sizeof grafo);
    for(int i = 0; i < 110; i++) grafo[i][i] = 0;
    for(int i = 0; i < m; i++){
      int a, b, w;
      scanf("%d %d %d",&a,&b,&w);
      a--; b--;
      grafo[a][b] = w;
      grafo[b][a] = w;
    }
    int k; scanf("%d",&k);
    //printf("Instancia %d\n",caso++);
    floyd_warshall();
    while(k--){
      int i, j;
      scanf("%d %d",&i,&j);
      i--; j--;
      printf("%d\n",grafo[i][j]);
    }
    //putchar('\n');
  }
  return 0;
}
