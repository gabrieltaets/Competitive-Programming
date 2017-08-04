#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int n, m, ans, tans;
  while((cin >> m >> n) && (n || m)){
    ans = m;
    int item[n+5];
    string str;
    for(int i = 0; i < n; i++) {
      cin >> str;
      item[i] = stoi(str,NULL,2);
    }
    for(int i = 1; i < (1<<m); i++){
      set<int> s;
      for(int j = 0; j < n; j++){
        int x = 0;
        for(int k = 0; k < m; k++){
          if(i&(1<<k)){
            x <<= 1;
            if(item[j]&(1<<k)) x++;
          }
        }
        s.insert(x);
      }
      tans = 0;
      for(int j = 0; j < m; j++){
        if(i&(1<<j)) tans++;
      }
      if(s.size() == n) ans = min(ans,tans);
    }
    cout << ans << endl;
  }
  return 0;
}
