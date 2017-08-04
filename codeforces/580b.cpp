#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ii friends[100010], cumulative[100010];

int main(){
  int n, d;
  cin >> n >> d;
  friends[0] = ii(0,0);
  for(int i = 1; i <= n; i++) cin >> friends[i].F >> friends[i].S;
  sort(friends+1,friends+n+1);
  cumulative[0] = friends[0];
  for(int i = 1; i <= n; i++) cumulative[i] = ii(cumulative[i-1].F+friends[i].F,cumulative[i-1].S+friends[i].S);
  
  int p1, p2;
  ll ans = 0;
  for(p1 = p2 = 1; p1 <= n && p2 <= n;){
    ll partial = cumulative[p2].S-cumulative[p1-1].S;
    if(partial > ans){
      printf("Answer at [%d,%d] = %d (%d)\n",p1,p2,partial,friends[p2].F-friends[p1].F);
      ans = partial;
    }
    if(friends[p2+1].F-friends[p1].F < d) p2++;
    else p1++;
    if(p1 > p2) p2 = p1;
  }
  cout << ans << endl;
  return 0;
}
