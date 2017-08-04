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
int memo[105][205];
double pd[105][205];
double ans;
void calc(int l, int s){
  if(memo[l][s]) {
    if(l == 1) ans += (double)l/(l+s);
    return;
  }
  memo[l][s] = 1;
  if(l == 0){
    pd[l][s] = 0;
  }
  else if(s == 0){
    pd[l][s] = 1;
  }
  else {
    pd[l][s] = (double)l/(l+s);
  }
  if(l) calc(l-1,s+1);
  if(s) calc(l,s-1);
  if(l == 1) ans += (double)l/(l+s);
}

int main(){
  int l, s;
  memset(memo,0,sizeof memo);
  for(int i = 0; i <= 100; i++) for(int j = 0; j <= 200; j++) pd[i][j] = 0;
  while(cin >> l >> s && (l || s)){
    ans = 0;
    calc(l,s);
    cout << ans << endl;
  }
  return 0;
}
