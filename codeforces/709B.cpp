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

int chk[100010];
int up, down;
int n, a;

ll solveDown(int pos, int nxt, bool flag){
  if(nxt >= n) return 0;
  if(nxt == n-1){
    if(flag) return 0;
    return chk[n-1]-chk[n-2];
  }
  if(nxt == 0){
    return min(solveDown(nxt,up,true)+chk[pos]-chk[nxt],solveDown(up,up+1,false)+chk[up]-chk[pos]);
  }
  if(nxt >= up){
    return solveDown(nxt,nxt+1,flag)+chk[nxt]-chk[pos];
  }
  else {
    return solveDown(nxt,nxt-1,flag)+chk[pos]-chk[nxt];
  }
}

ll solveUp(int pos, int nxt, bool flag){
  if(nxt < 0) return 0;
  if(nxt == 0){
    if(flag) return 0;
    return chk[pos]-chk[nxt];
  }
  if(nxt == n-1){
    ll a = solveUp(nxt,down,true)+chk[nxt]-chk[pos];
    ll b = solveUp(down,down-1,false)+chk[pos]-chk[down];
    return min(a,b);
  }
  if(nxt >= up){
    return solveUp(nxt,nxt+1,flag)+chk[nxt]-chk[pos];
  }
  else {
    return solveUp(nxt,nxt-1,flag)+chk[pos]-chk[nxt];
  }
}

int main(){
  ii closestUp(INF,-1), closestDown(INF,-1);
  scanf("%d %d",&n,&a);
  for(int i = 0; i < n; i++){
    scanf("%d",chk+i);
    if(chk[i] > a && chk[i]-a < closestUp.F) closestUp = mp(chk[i]-a,chk[i]);
    if(chk[i] < a && a-chk[i] < closestDown.F) closestDown = mp(a-chk[i],chk[i]);
  }
  chk[n] = a;
  if(n == 1){
    printf("0\n");
    return 0;
  }
  if(n == 2){
    printf("%d\n",min(abs(a-chk[0]),abs(a-chk[1])));
    return 0;
  }
  sort(chk,chk+n);
  down = -1, up = -1;
  ii start(INF,-1);
  ll dist = 0;
  for(int i = 0; i < n; i++){
    if(chk[i] == closestUp.S && up==-1) up = i;
    if(chk[i] == closestDown.S) down = i;
    if(abs(a-chk[i])<start.F) start = mp(abs(a-chk[i]),i);
  }
  dist = start.F;
  for(int i = 1; i < n-2; i++){
    dist += chk[i+1]-chk[i];
  }
  if(closestUp.F == INF && closestDown.F == INF){
    printf("0\n");
    return 0;
  }
  if(closestUp.F == INF){
    dist += chk[n-1]-chk[n-2];
    printf("%lld\n",dist);
    return 0;
  }
  if(closestDown.F == INF){
    dist += chk[1]-chk[0];
    printf("%lld\n",dist);
    return 0;
  }
  cout << min(solveDown(n,down,false),solveUp(n,up,false)) << endl;
  return 0;
}
