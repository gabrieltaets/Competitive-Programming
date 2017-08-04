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
ii bid[200035];
vi b[200035];
vii wins;
int main(){
  int n, q;
  scanf("%d",&n);
  set<int> c;
  for(int i = 0; i < n; i++){
    scanf("%d %d",&bid[i].F,&bid[i].S);
    c.insert(bid[i].F);
    b[bid[i].F].pb(bid[i].S);
  }
  for(set<int>::iterator it = c.begin(); it != c.end(); it++){
    wins.pb({b[*it][b[*it].size()-1],*it});
  }
  sort(wins.begin(),wins.end());
  
  scanf("%d",&q);
  while(q--){
    int k;
    scanf("%d",&k);
    set<int> rmv;
    for(int i = 0; i < k; i++){
      int x;
      scanf("%d",&x);
      if(c.count(x)) rmv.insert(x);
    }
    
    if(rmv.size() == c.size()){
      printf("0 0\n");
      continue;
    }
    int first = -1, second = -1;
    for(int i = wins.size()-1; i >= 0; i--){
      if(rmv.count(wins[i].S)) continue;
      if(first == -1) first = wins[i].S;
      else {
        second = i;
        break;
      }
    }
    printf("%d %d\n",first,*lower_bound(b[first].begin(),b[first].end(),second==-1?-1:wins[second].F));
  }
  return 0;
}
