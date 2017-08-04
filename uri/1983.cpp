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
  scanf("%d",&n);
  pair<double,int> p(0.0,0);
  for(int i = 0; i < n; i++){
    pair<double,int> x;
    cin >> x.second >> x.first;
    p = max(x,p);
  }
  if(p.first < 8) cout << "Minimum note not reached\n";
  else cout << p.second << endl;
  return 0;
}