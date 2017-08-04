#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
      int x;
      scanf("%d",&x);
      s.insert(x);
    }
    printf("%d\n",s.size());
  }
  return 0;
}