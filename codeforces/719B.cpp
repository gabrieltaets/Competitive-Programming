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

int calc2(int rp, int ro, int bp, int bo){
  int sum = 0;
  sum += min(rp,bo);
  ro += sum;
  bp += sum;
  rp -= sum;
  bo -= sum;
  sum += rp + bo;
  return sum;
}

int calc1(int rp, int ro, int bp, int bo){
  int sum = 0;
  sum += min(ro,bp);
  rp += sum;
  bo += sum;
  bp -= sum;
  ro -= sum;
  sum += ro + bp;
  return sum;
}

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  int rp = 0, ro =0, bp = 0, bo = 0, rt = 0, bt = 0;
  for(int i = 0; i < n; i++){
    if(i&1){
      if(str[i] == 'r') ro++;
      else bo++;
    }
    else {
      if(str[i] == 'r') rp++;
      else bp++;
    }
    str[i] == 'r' ? rt++:bt++;
  }
  int total = min(calc1(rp,ro,bp,bo),calc2(rp,ro,bp,bo));
  printf("%d\n",total);
  return 0;
}
