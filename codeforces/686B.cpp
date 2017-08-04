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
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    ii m(2000000000,0);
    for(int j = i; j < n; j++){
      m = min(m,ii(a[j],j));
    }
    for(int j = m.S; j > i; j--){
      printf("%d %d\n",j,j+1);
      swap(a[j-1],a[j]);
    }
  }
  //for(int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
