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
  int lat = 0;
  while(n--){
    int x;
    string dir;
    cin >> x >> dir;
    if((lat == 0 && dir != "South") || (lat == 20000 && dir != "North") || (dir == "North" && lat - x < 0) || (dir == "South" && lat+x > 20000)){
      printf("NO\n");
      return 0;
    }
    if(dir == "North"){
      lat -= x;
      if(lat < 0) lat *= -1;
    }
    if(dir == "South"){
      lat += x;
      if(lat > 20000) lat = 20000-lat;
    }
  }
  if(lat) cout << "NO\n";
  else cout << "YES\n";
  return 0;
}
