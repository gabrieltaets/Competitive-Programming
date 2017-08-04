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
  int n;
  cin >> n;
  bool good = false;
  while(n--){
    int b, a;
    string str;
    cin >> str >> b >> a;
    if(b >= 2400 && a > b) good = true;
  }
  if(good) printf("YES\n");
  else printf("NO\n");
  return 0;
}
