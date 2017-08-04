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
  string str;
  cin >> str;
  stack<int> st;
  for(int i = str.size()-1; i >= 0; i--){
    st.push(i+1);
    if(str[i] == 'M') break;
  }
  cout << st.size() << endl;
  cout << st.top();
  st.pop();
  while(!st.empty()){
    cout << " " << st.top();
    st.pop();
  }
  cout << endl;
  return 0;
}
