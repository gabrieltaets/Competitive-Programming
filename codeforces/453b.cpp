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
  double c = clock();
  scanf("%d",&n);
  int v[n], r[n], h[70], ans[n], d, s = 0x3f3f3f3f;
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }
  srand(time(NULL));
  for(ll i = 0;;i++){
    memset(h,0,sizeof h);
    d = 0;
    for(int j = 0; j < n; j++){
      r[j] = rand()%60+1;
      if(r[j] != 1 && h[j]){
        j--;
        continue;
      }
      int k;
      for(k = 0; k < j; k++){
        if(__gcd(r[j],r[k]) != 1) break;
      }
      if(j != k){
        j--;
        continue;
      }
      d += abs(v[j] - r[j]);
      h[r[j]] = 1;
    }
    if(d < s){
      printf("Found new answer (%d): ",d);
      for(int j = 0; j < n; j++) {
        ans[j] = r[j];
        printf("%d ",r[j]);
      }
      putchar('\n');
      s = d;
    }
    if(i % 100000 == 0 && (clock()-c)/CLOCKS_PER_SEC >= 600) {
      printf("Break after %lf seconds\n",(clock()-c)/CLOCKS_PER_SEC);
      break;
    }
  }
  for(int i = 0; i < n; i++){
    printf("%d ",ans[i]);
  }
  putchar('\n');
  return 0;
}
