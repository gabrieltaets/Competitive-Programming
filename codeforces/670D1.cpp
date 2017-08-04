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
  int n, k;
  scanf("%d %d",&n,&k);
  int a[1010], b[1010], q = 0, cookies = 0, t = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d",a+i);
    t += a[i];
  }
  for(int i = 0; i < n; i++) {
    scanf("%d",b+i);
    //cookies = min(cookies,b[i]/a[i]);
  }
  while(q <= k){
    q = 0;
    for(int i = 0; i < n; i++){
      if(a[i] > b[i]) {
        q += a[i]-b[i];
        b[i] = a[i];
      }
      b[i] -= a[i];
    }
    if(q <= k){
      cookies++;
      k -= q;
    }    
  }
  cout << cookies << endl;
  return 0;
}
