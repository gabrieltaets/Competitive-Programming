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
char str[1005][110];
int main(){
  int n, m, q, k;
  scanf("%d %d %d %d",&n,&m,&q,&k);
  for(int i = 0; i < n; i++){
    scanf("%s",str[i]);
  }
  char in[110];
  for(int i = 0; i < q; i++){
    scanf("%s",&in);
    bool ans = false;
    for(int j = 0; !ans && j < n; j++){
      int cont = 0;
      for(int x = 0; !ans && x < m; x++){
        if(in[x] != str[j][x]) cont++;
      }
      if(cont <= k) ans = true;
    }
    printf("%c\n",ans?'S':'N');
  }
  return 0;
}
