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
bool inCol[100010], inRow[100010];
int main(){
  int n, m;
  scanf("%d %d",&n,&m);
  int difCol = 0, difRow = 0;
  ll unseen = (ll)n*n;
  for(int i = 0; i < m; i++){
    int x, y;
    scanf("%d %d",&x,&y);
    if(!inRow[x]){
      inRow[x] = true;
      unseen -= n;
      unseen += difCol;
      difRow++;
    }
    if(!inCol[y]){
      inCol[y] = true;
      unseen -= n;
      unseen += difRow;
      difCol++;
    }
    printf("%lld ",unseen);
  }
  return 0;
}
