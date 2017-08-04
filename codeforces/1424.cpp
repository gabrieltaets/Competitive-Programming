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
int main(){
  int n, m;
  while(scanf("%d %d",&n,&m)!=EOF){
    vi freq[100010];
    for(int i = 0; i < n; i++){
      int x;
      scanf("%d",&x);
      freq[x].pb(i+1);
    }
    for(int i = 0; i < m; i++){
      int x, k;
      scanf("%d %d",&k,&x);
      if(x > 100000 || k > freq[x].size()){
        printf("0\n");
        continue;
      }
      printf("%d\n",freq[x][k-1]);
    }
  }  
  return 0;
}
