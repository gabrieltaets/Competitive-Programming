#include <bits/stdc++.h>
#define DRAW 1
#define WIN 2
#define LOSE 0
using namespace std;
int n, m, g, q;
vector<int> t[45][45];

bool solve(){
  int sum[45], ma = -1, mai = -1, mi = 0x3f3f3f3f, mii = -1, chgq[45], chg[45][45];
  memset(sum,0,sizeof sum);
  memset(chgq,0,sizeof chgq);
  memset(chg,0,sizeof chg);
  for(int i = 1; i < n; i++){
    for(int j = t[0][i].size(); j < m; j++){
      t[0][i].push_back(WIN);
      t[i][0].push_back(LOSE);
    }
    for(int j = 0; j < t[0][i].size(); j++){
      sum[0] += t[0][i][j];
    }
  }
  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      if(i == j) continue;
      for(int k = t[i][j].size(); k <= m; k++){
        t[i][j].push_back(DRAW);
        t[j][i].push_back(DRAW);
        chg[i][j]++; chg[j][i]++;
        chgq[i]++; chgq[j]++;
      }
      for(int k = 0; k < t[i][j].size(); k++){
        sum[i] += t[i][j][k];
        if(sum[i] > ma || (mai != -1 && sum[i] == ma && chgq[i] > chgq[mai])){
          ma = sum[i];
          mai = i;
        }
        if(sum[i] < mi || (mii != -1 && sum[i] == mi && chgq[i] > chgq[mii])){
          mi = sum[i];
          mii = i;
        }
      }
    }
  }
  if(sum[0] > ma) return true;
  if(ma == mi) return false;
  return false;
}

int main(){
  while(scanf("%d %d %d",&n,&m,&g) && (n || m || g)){
    for(int i = 0; i < 45; i++) for(int j = 0; j < 45; j++) t[i][j].clear();
    int x, y;
    char r;
    q = n*m/2;
    for(int i = 0; i < g; i++){
      scanf("%d %c %d",&x,&r,&y);
      if(r == '='){
        t[x][y].push_back(DRAW);
        t[y][x].push_back(DRAW);
      }
      else if(r == '>'){
        t[x][y].push_back(WIN);
        t[x][y].push_back(LOSE);
      }
      else {
        t[x][y].push_back(LOSE);
        t[y][x].push_back(WIN);
      }
    }
    printf("%s\n",solve() ? "Y":"N");
  }
  return 0;
}