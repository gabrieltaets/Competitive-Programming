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
  map<string,int> dia;
  dia["monday"] = 0;
  dia["tuesday"] = 1;
  dia["wednesday"] = 2;
  dia["thursday"] = 3;
  dia["friday"] = 4;
  dia["saturday"] = 5;
  dia["sunday"] = 6;
  string d1, d2;
  while(cin >> d1 >> d2){
    int nd1 = dia[d1], nd2 = dia[d2];
    int at = nd1;
    if(nd1 == nd2 || nd2 == (nd1+2)%7 || nd2 == (nd1+3)%7) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
