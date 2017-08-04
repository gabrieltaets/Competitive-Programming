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

bool seen[100010];
int main(){
  mt19937 mt(time(NULL));
  int n = 100000;
  cout << n << endl;
  for(int i = 0; i < n; i++){
    cout << mt()%1000000000 << " ";  
  }
  cout << endl;
  for(int i = 0; i < n; i++){
    int p = mt()%n;
    if(seen[p]){
      i--;
      continue;
    }
    seen[p] = 1;
    cout << p+1 << " ";
  }
  cout << endl;
  return 0;
}
