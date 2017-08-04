#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define MAXN 300010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int unread[MAXN], readUntil[MAXN], N, q;
ii generated[MAXN];

int main(){
  memset(unread,0,sizeof unread);
  memset(readUntil,0,sizeof readUntil);
  scanf("%d %d",&N,&q);
  int last = 0, ans = 0, front = 0;
  for(int t = 1; t <= q; t++){
    int type, x;
    scanf("%d %d",&type,&x);
    if(type == 1){
      generated[front++] = ii(x,t);
      unread[x]++;
      ans++;
    }
    else if(type == 2){
      ans -= unread[x];
      unread[x] = 0;
      readUntil[x] = t;
    }
    else {
      for(int i = last; i < x; i++){
        if(unread[generated[i].F] && readUntil[generated[i].F] < generated[i].S){
          readUntil[generated[i].F] = generated[i].S;
          unread[generated[i].F]--;
          ans--;
        }
      }
      last = x;
    }
    printf("%d\n",ans);
  }
  return 0;
}