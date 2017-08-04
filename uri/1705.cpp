#include <bits/stdc++.h>
using namespace std;
long long power10(int e){
  if(e == 0) return 1;
  long long ans = power10(e/2);
  ans *= ans;
  if(e&1) ans *= 10;
  return ans;  
}
int main(){
  long long N;
  vector<long long> v;
  long long num = 0, ans = -1;
  for(int i = 1; i < (1<<12); i++){
    num = 0;
    for(int j = 0; j < 12; j++){
      if(i&(1<<j)) num += power10(j);
    }
    v.push_back(num);
  }
  while(scanf("%lld",&N) != EOF){
    ans = -1;
    int lo = 0, hi = v.size()-1, mid;
    while(lo <= hi){
      mid = ((lo+hi)>>1);
      if(v[mid] == N) break;
      if(v[mid] > N) lo = mid+1;
      else hi = mid-1;
    }
    for(int i = 0; i < v.size(); i++){
      if(v[i]%N==0) {
        ans = v[i];
        break;
      }
    }
    printf("%lld\n",ans);  
  }
  return 0;
}