#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> Vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int a, n;
  cin >> n >> a;
  a--;
  int c[n];
  for(int i = 0; i < n; i++) cin >> c[i];
  int sum = 0;
  for(int i = 0; i <= n; i++){
    if(a-i < 0 && a+i >= n) break;
    if(a-i < 0 && a+i < n && c[a+i]) {
      sum++;
      //printf("d=%d+\n",i);
    }
    else if(a-i >= 0 && a+i >= n && c[a-i]) {
      sum++;
      //printf("d=%d-\n",i);
    }
    else if(a-i >= 0 && a+i < n && c[a-i] && c[a+i]) {
      if(i) sum+=2;
      else sum++;
      //printf("d=%d\n",i);
    }
  }
  cout << sum << endl;
  return 0;
}
