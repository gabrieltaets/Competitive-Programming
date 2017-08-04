#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
int dis[260][260];
int cost[260];
int main(){
  int N, M, C, K;
  while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
    for (int i = 0; i < N; ++i) {
      cost[i] = INF;
      fill(dis[i], dis[i]+N, INF);
      dis[i][i] = 0;
    }
    int u, v, d;
    for (int i = 0; i < M; ++i) {
      scanf("%d %d %d", &u, &v, &d);
      dis[u][v] = dis[v][u] = d;
    }
    for (int i = C-2; i >= 0; --i)
      dis[i][C-1] = dis[i][i+1] + dis[i+1][C-1];

    queue<int> Q;
    bool inQueue[260] = {0};
    Q.push(K);
    cost[K] = 0;
    inQueue[K] = true;
    while (!Q.empty()) {
      int cur = Q.front();
      inQueue[cur] = false;
      Q.pop();
      for (int nxt = 0; nxt < N; ++nxt) {
        if (cost[nxt] > cost[cur] + dis[cur][nxt]) {
          cost[nxt] = cost[cur] + dis[cur][nxt];
          if (nxt < C) { 
            cost[C-1] = min(cost[C-1], cost[nxt] + dis[nxt][C-1]);
          }
          else if (!inQueue[nxt]) {
            Q.push(nxt);
            inQueue[nxt] = true;
          }
        }
      }
    }
    printf("%d\n", cost[C-1]);
  }
  return 0;
}