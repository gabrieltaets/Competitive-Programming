#include <bits/stdc++.h>
using namespace std;
int k;
string n;
string solve(int x){
  set<char> s;
  set<char>::iterator it;
  bool vis[10];
  memset(vis,false,sizeof vis);
  string ans;
  char menor = 127, minma = 127;
  if(n[x] == '9') return "-1";
  //printf("n[%d] = %d (%c)\n",x,n[x],n[x]);
  for(int i = 0; i < x; i++) {
    s.insert(n[i]);
    vis[n[i]-'0'] = true;
    if(n[i] <= menor) menor = n[i];
    //if(n[i] > n[x] && n[i] < minma) minma = n[i];
  }
  int dif = k - s.size();
  if(s.size() >= k) return "-1";
  if(abs(dif) > n.size() - x) return "-1";
  ans = n;
  if(!x){
    if(n[x] == '9') return "-1";
    //printf("HERE: ");
    ans[x]++;
    int y = 0;
    for(int i = x+1; i < ans.size()-k+2; i++){
      ans[i] = '0';
    }
    for(int i = ans.size()-k+2; i < ans.size(); i++){
      ans[i] = '2'+y++;
    }
    //cout << ans << endl;
  }
  else {
    //if(x == 2) printf("ELSE\n");
    if(dif)
      for(int j = 0; j < 10; j++){
        if(!vis[j] && j+'0' > n[x]) {
          ans[x] = j+'0';
          vis[j] = true;
          dif--;
          break;
        }
      }
    for(int i = ans.size()-dif; i < ans.size(); i++){
      for(int j = 0; j < 10; j++){
        if(!vis[j]) {
          ans[i] = j+'0';
          vis[j] = true;
          dif--;
          break;
        }
      }
    }
    if(dif) return "-1";
    char men = 127;
    for(int i = 0; i < 10; i++){
      if(vis[i]){
        men = i+'0';
        break;
      }
    }
    for(int i = x + 1; i < ans.size()-dif; i++){
      ans[i] = men;
    }
  }
  //cout << "Returning success for " << x << endl;
  return ans;
}
int main(){
  int t;
  scanf("%d",&t);
  for(int c = 1; c <= t; c++){
    string ans;
    cin >> n >> k;
    printf("Caso %d: ",c);
    if(n.size() < k){
      for(int i = k-1; i > 1; i--) ans.push_back(i+'0');
      ans += "01";
      reverse(ans.begin(),ans.end());
      cout << ans << endl;
      continue;
    }
    else if(n.size() == k){
      set<char> s;
      for(int i = 0; i < n.size(); i++) s.insert(n[i]);
      if(s.size() == k) {
        cout << n << endl;
        continue;
      }
    }
    else if(k == 1){
      char st = n[0], ma = 0;
      for(int i = 1; i < n.size(); i++){
        ma = max(ma,n[i]);
      }
      if(ma <= st){
        for(int i = 0; i < n.size(); i++)
          putchar(st);
        putchar('\n');
        continue;
      }
      else if(st == '9'){
        for(int i = 0; i <= n.size(); i++)
          putchar('1');
        putchar('\n');
        continue;
      }
      else {
        for(int i = 0;i < n.size(); i++)
          putchar(st+1);
        putchar('\n');
        continue;
      }
    }
    int x = n.size()-1;
    while(x >= 0){
      ans = solve(x);
      x--;
      if(ans != "-1") break;
    }
    if(x == -1){
      n = "0" + n;
      ans = solve(0);
    }
    cout << ans << endl;
  }
  return 0;
}