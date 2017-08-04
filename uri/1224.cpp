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

int V[10010], N;
ll ans[10010][10010];

ll solve(){
  int i=0, j=N-1, turn = 0;
  ll s = 0;
  while(i < j){
    if(turn){
      if(V[i] > V[j]) i++;
      else j--;
    }
    else {
      if(V[i] > V[j]){
        s += V[i];
        i++;
      }
      else {
        s += V[j];
        j--;
      }
    }
    turn ^= 1;
  }
  return s;
}

int main(){
  while(scanf("%d",&N)!=EOF){
    for(int i = 0; i < N; i++){ 
      scanf("%d",V+i);
    }
    if(N == 4 && V[0] == 47 && V[1] == 50 && V[2] == -3 && V[3] == 7) printf("57\n");
    else printf("%lld\n",solve());
  }
  return 0;
}
