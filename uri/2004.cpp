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
  int q;
  cin >> q;
  while(q--){
    int n, p, t;
    int a[110];
    for(int i = 0; i <= 100; i++) a[i] = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> t >> p;
      if(a[t] == 0) a[t] = p;
      else if(a[t] >= 10 && a[t] <= 100){
        if(p >= 10 && p <= 100 && p > a[t]) a[t] = p;
      }
      else if(a[t] < 10 || a[t] > 100){
        if(p >= 10 && p <= 100) a[t] = p;
        else a[t] = max(a[t],p);
      }
    }
    int s = 0;
    for(int i = 0; i <= 100; i++) s += a[i];
    cout << s << endl;
  }
  return 0;
}
