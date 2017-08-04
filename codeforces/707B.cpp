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

int n, m, k;
vii graph[100100];
int isCentre[100100];
vi centre;

int main(){
  scanf("%d %d %d",&n,&m,&k);
  for(int i = 0; i < m; i++){
    int u, v, l;
    scanf("%d %d %d",&u,&v,&l);
    graph[u].pb(mp(v,l));
    graph[v].pb(mp(u,l));
  }
  memset(isCentre,0,sizeof isCentre);
  if(k){
    for(int i = 0; i < k; i++){
      int c;
      scanf("%d",&c);
      centre.pb(c);
      isCentre[c] = 1;
    }
  }
  int rubles = INF;
  for(int i = 0; i < centre.size(); i++){
    int c = centre[i];
    for(int j = 0; j < graph[c].size(); j++){
      int x = graph[c][j].F, w = graph[c][j].S;
      if(!isCentre[x] && w < rubles) rubles = w;
    }
  }
  printf("%d\n",rubles==INF?-1:rubles);
  return 0;
}
