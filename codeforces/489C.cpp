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
  int m, s;
  cin >> m >> s;
  string sm(m,'0'), la(m,'0');
  int sum = s;
  for(int i = 0; i < m; i++){
    la[i] = '0'+min(sum,9);
    sum -= min(sum,9);
  }
  if(sum){
    printf("-1 -1\n");
    return 0;
  }
  sum = s;
  for(int i = m-1; i >= 0; i--){
    sm[i] = '0' + min(sum,9);
    sum -= min(sum,9);
  }
  if(sm[0] == '0' && m > 1){
    for(int i = 1; i < m; i++){
      if(sm[i] > '0'){
        sm[i]--;
        sm[0]++;
        cout << sm << " " << la << endl;
        return 0;
      }
    }
    printf("-1 -1\n");
  }
  else cout << sm << " " << la << endl;
  return 0;
}
