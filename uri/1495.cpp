#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  ll n, g;
  while(cin >> n >> g){
    ll pts = 0;
    priority_queue <int,vi,greater<int> > pq;
    for(int i = 0; i < n; i++){
      int x, y;
      scanf("%d %d",&x,&y);
      if(x > y) pts += 3;
      else {
        pq.push(y-x+1);
      }
    }
    while(!pq.empty()){
      int a = pq.top(); pq.pop();
      if(g >= a){
        g -= a;
        pts += 3;
      }
      else if(g == a-1){
        pts++;
        g -= a-1;
      }
    }
    cout << pts << endl;
  }
  return 0;
}