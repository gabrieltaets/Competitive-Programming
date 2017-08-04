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
  int a, b;
  cin >> a >> b;
  stack<int> st;
  while(b){
    st.push(b);
    if(b%2 == 1){
      if(b % 10 != 1) break;
      b /= 10;
    }
    else {
      b /= 2;
    }
    if(b == a){
      st.push(a);
      break;
    }
  }
  if(st.top() == a){
    cout << "YES\n" << st.size() << endl;
    while(!st.empty()){
      printf("%d ",st.top());
      st.pop();
    }
  }
  else cout << "NO\n";
  return 0;
}
