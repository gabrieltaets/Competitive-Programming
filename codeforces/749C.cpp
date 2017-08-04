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

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  queue<ll> d, r;
  for(int i = 0; i < n; i++){
    if(str[i] == 'D') d.push((ll)i);
    else r.push((ll)i);
  }
  while(!d.empty() && !r.empty()){
    if(d.front() < r.front()) {
      r.pop();
      d.push(d.front()+n);
      d.pop();
    }
    else {
      d.pop();
      r.push(r.front()+n);
      r.pop();
    }
  }
  if(d.empty()) printf("R\n");
  else printf("D\n");
  return 0;
}
