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
  int n, m;
  scanf("%d %d",&n,&m);
  bool colored = false;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char color;
      scanf(" %c",&color);
      if(color == 'M' || color == 'Y' || color == 'C') colored = true;
    }
  }
  printf("%s\n",colored?"#Color":"#Black&White");
  return 0;
}
