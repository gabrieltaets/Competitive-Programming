#include <bits/stdc++.h>
using namespace std;
int N, pd[200010], cor[200010];
bool memo[200010];
vector<int> colors[200010];

int solve(int pos){
  if(pos == N-1) return 0;
  if(memo[pos]) return pd[pos];
  memo[pos] = true;
  pd[pos] = min(pd[pos],solve(pos+1)+1);
  int lo = 0, hi = colors[cor[pos]].size()-1, mid;
  while(lo <= hi){
    mid = ((lo+hi)>>1);
    if(colors[cor[pos]][mid] == pos) break;
    else if(colors[cor[pos]][mid] > pos) hi = mid-1;
    else lo = mid+1;
  }
  if(mid != colors[cor[pos]].size()-1){
    pd[pos] = min(pd[pos],solve(colors[cor[pos]][mid+1])+1);
  }
  return pd[pos];
}

int main(){
  scanf("%d",&N);
  for(int i = 0; i <= N; i++) {
    pd[i] = 0x3f3f3f3f;
    memo[i] = false;
  }
  for(int i = 0; i < N; i++){
    scanf("%d",&cor[i]);
    colors[cor[i]].push_back(i);
  }
  printf("%d\n",solve(0));
  return 0;
}

