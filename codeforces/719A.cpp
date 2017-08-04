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
  int n;
  scanf("%d",&n);
  int last=-1, before=-1;
  for(int i = 0; i < n; i++){
    before = last;
    scanf("%d",&last);
  }
  if(last == 15) printf("DOWN\n");
  else if(last == 0) printf("UP\n");
  else {
    if(before == -1) printf("-1\n");
    else if(before > last) printf("DOWN\n");
    else printf("UP\n");
  }
  return 0;
}
