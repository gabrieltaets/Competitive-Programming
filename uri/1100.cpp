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

ii s, d;
ii moves[] = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };

bool isValid(ii x){
  if(x.F < 1 || x.F > 8 || x.S < 1 || x.S > 8) return false;
  return true;
}

int bfs(){
  int dist[10][10];
  memset(dist,INF,sizeof dist);
  dist[s.F][s.S] = 0;
  queue<ii> q;
  q.push(s);
  while(!q.empty()){
    ii a = q.front(); q.pop();
    for(int i = 0; i < 8; i++){
      ii x = {a.F+moves[i].F, a.S+moves[i].S};
      if(isValid(x)){
        if(dist[x.F][x.S] != INF) continue;
        dist[x.F][x.S] = dist[a.F][a.S]+1;
        q.push(x);
      }
    }
  }
  return dist[d.F][d.S];
}

int main(){
  char c1, c2;
  int n1, n2;
  while(scanf(" %c%d %c%d",&c1,&n1,&c2,&n2)!=EOF){
    s = {c1-'a'+1,n1};
    d = {c2-'a'+1,n2};
    //printf("{%d,%d} {%d, %d}",s.F,s.S,d.F,d.S);
    printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,n1,c2,n2,bfs());
  }
  return 0;
}
