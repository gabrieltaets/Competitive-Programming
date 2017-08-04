#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    int res = 2015 - x;
    if(res <= 0) res--;
    cout << abs(res) << (res>0?" D.C.":" A.C.") << endl;
  }
  return 0;
}