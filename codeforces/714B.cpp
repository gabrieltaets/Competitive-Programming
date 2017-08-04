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
  scanf("%d",&n);
  set<int> s;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    s.insert(x);
  }
  if(s.size() > 3){
    cout << "NO\n";
    return 0;
  }
  if(s.size() <= 2){
    cout << "YES\n";
    return 0;
  }
  vi v(s.begin(),s.end());
  sort(v.begin(),v.end());
  if(v[2]-v[1] == v[1]-v[0]) cout << "YES\n";
  return 0;
}
