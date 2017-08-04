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

bool isPower2(int x){
  int cnt = 0;
  for(int i = 0; i < 32; i++){
    if(x&(1<<i)) cnt++;
  }
  return cnt==1;
}

int main(){
  int n, m;
  scanf("%d %d",&n,&m);
  int k = INF;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    if(isPower2(x)){
      m &= ~x;
    }
  }
  putchar(m?'N':'S');
  return 0;
}
