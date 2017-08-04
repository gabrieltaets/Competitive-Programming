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
int n, x, y;
int tam[20];
int sum[1<<15];
bool pd[105][1<<15];
bool memo[105][1<<15];

int side(int a, int bmask){
  int s = sum[bmask]/a;
  if(a*s != sum[bmask]) return -1;
  return s;
}

int count(int bmask){
  int s = 0;
  for(int i = 0; i < n; i++){
    if(bmask & (1 << i)) s++;
  }
  return s;
}

string show(int bmask){
  string s;
  for(int i = 0; i < n; i++){
    s.pb((bmask&(1<<i))?'1':'0');
  }
  return s;
}
int rec = 0;
bool solve(int a, int bmask){
  if(memo[a][bmask]) return pd[a][bmask];
  if(bmask == 0) return true;
  int b = side(a,bmask);
  if(a <= 0 || b <= 0 || a > x || b > y) return false;
  memo[a][bmask] = true;
  pd[a][bmask] = false;
  int bmask2 = 0, bmask1 = bmask, active = count(bmask);
  int step = rec++;
  if(active == 1) {
    printf("#%d %d x %d served to %d\n",step,a,b,(int)log2(bmask));
    return pd[a][bmask] = true;
  }
  for(int i = 0; i < (1<<n); i++){
    bool flag = false;
    bmask1 = bmask; bmask2 = 0;
    for(int j = 0; j < n && !flag; j++){
      if(((bmask & (1<<j)) == 0) && (i & (1<<j))) {
        flag = true;
        break;
      }
      if((bmask & (1<<j)) && ((i & (1<<j)) == 0)){
        bmask1 -= (1<<j);
        bmask2 += (1<<j);
      }
    }
    if(flag) continue;
    for(int j = 1; j < a; j++){
      printf("#%d Calling (s(%d,%s) & s(%d,%s))||(s(%d,%s) & s(%d,%s))\n",step,j,show(bmask1).c_str(),a-j,show(bmask2).c_str(),j,show(bmask2).c_str(),a-j,show(bmask1).c_str());
      pd[a][bmask] = (solve(j,bmask1) && solve(a-j,bmask2)) || (solve(j,bmask2) && solve(a-j,bmask1));
      printf("#%d Returned (%d & %d)||(%d & %d) - Size %dx%d\n",step,solve(j,bmask1),solve(a-j,bmask2),solve(j,bmask2),solve(a-j,bmask1),a,b);
    }
  }
  return pd[a][bmask];
}

int main(){
  int c = 1;
  while((cin >> n) && n){
    cin >> x >> y;
    for(int i = 0; i < n; i++){
      scanf("%d",&tam[i]);
    }
    for(int i = 1; i < (1<<n); i++){
      int s = 0;
      for(int j = 0; j < n; j++){
        if(i&(1<<j)) s += tam[j];
      }
      sum[i] = s;
    }
    printf("Case %d: %s\n",c++,solve(x,(1<<n)-1)?"Yes":"No");
  }
  return 0;
}
