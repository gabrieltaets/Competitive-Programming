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

map<ll,int> m;

ll change(ll x){
  string str = to_string(x);
  for(int i = 0; i < str.size(); i++){
    str[i] = (str[i]-'0')%2+'0';
  }
  return stoll(str);
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    char op;
    ll x;
    scanf(" %c %lld",&op,&x);
    if(op == '+'){
      m[change(x)]++;
    }
    if(op == '-'){
      m[change(x)]--;
    }
    if(op == '?'){
      cout << m[change(x)] << endl;
    }
  }
  return 0;
}
