#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100010];
bool solve(int i, long long sum){
  if(sum%m==0) return true;
  if(i == n) return false;
  bool ans = solve(i+1,sum+a[i]);
  if(ans) return ans;
  else return solve(i+1,sum);
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  set<int> s;
  bool ans = false;
  for(int i = 0; i < n; i++){
    if(s.find(a[i]) == s.end()){
      s.insert(a[i]);
      ans |= solve(i,a[i]);
    }
    if(ans) break;
  }
  cout << (ans ? "YES\n" : "NO\n");
  return 0;
}