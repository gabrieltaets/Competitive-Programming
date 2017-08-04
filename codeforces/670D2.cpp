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

ll a[100010], b[100010], q = 0, cookies = 0;
int main(){
  ll n, k;
  scanf("%lld %lld",&n,&k);
  for(int i = 0; i < n; i++) {
    scanf("%lld",a+i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%lld",b+i);
  }
  ll lo = 0, hi = 3000000000LL, mid;
  while(lo <= hi){
    mid = (lo+hi)/2;
    q = k;
    //if(n == 100000) printf("Trying to cook %lld cookies\n",mid);
    for(int i = 0; i < n; i++){
      ll musti = mid*a[i];
      if(b[i] < musti){
        q -= musti-b[i];
      }
      if(q < 0) break;
    }
    //if(n == 100000) printf("Must use %lld powder (has %lld)\n",q,k);
    if(q > 0){
     // if(n == 100000) printf("May cook more cookies!\n");
      lo = mid+1;
      cookies = mid;
    }
    else if(q < 0){
     // if(n == 100000) printf("Must cook less cookies :(\n");
      hi = mid-1;
    }
    else {
      cookies = mid;
      break;
    }
  }
  cout << cookies << endl;
  return 0;
}
