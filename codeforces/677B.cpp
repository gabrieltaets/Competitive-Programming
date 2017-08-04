#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int n, h, k;
  cin >> n >> k >> h;
  long long s = 0;
  queue <int> q;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    q.push(x);
  }
  int in = 0;
  bool flag = false;
  while(!q.empty()){
    if(in + q.front() <= k){
      in += q.front();
      //printf("inserted %d\n",q.front());
      q.pop();
      continue;
    }
    else if(flag){
      flag = !flag;
      s++;
      in -= h;
    }
    s += (in/h);
    in %= h;
    flag = true;
    if(in < 0) in  = 0;
    //printf("Smashed %d\n",h);
  }
  s += (in/h);
  in %= h;
  if(in) s++;
  cout << s << endl;
  return 0;
}