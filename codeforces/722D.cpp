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

set<int> used;

int main(){
  int n;
  cin >> n;
  queue<int> q;
  vi v;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    v.pb(x);
  }
  sort(v.begin(),v.end());
  for(int i = n-1; i>=0; i--){
    q.push(v[i]);
    used.insert(v[i]);
  }
  int consec = 0;
  while(consec < n){
    int x = q.front(); q.pop();
    if(used.count((x>>1)) || (x>>1)==0){
      consec++;
      q.push(x);
    }
    else {
      consec = 0;
      used.erase(x);
      used.insert((x>>1));
      q.push((x>>1));
    }
  }
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}
