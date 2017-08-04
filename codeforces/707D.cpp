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
struct query {
  int op, i, j, k;
  query(){}
  query(int o, int a, int b = 0){
    op = o; i = a; j = b; k = a;
  }
};
bool save[100010];
bool shelf[1010][1010];
bool load[1010][1010];
int ans[100010];
int n, m, q;
vector<query> qs;

void solve(int x){
  for(int i = 0; i < q; i++){
    if(qs[i].op == 1){
      shelf[qs[i].i][qs[i].j] = 1;
    }
    if(qs[i].op == 2){
      shelf[qs[i].i][qs[i].j] = 0;
    }
    if(qs[i].op == 3){
      for(int j = 0; j < m; j++){
        shelf[qs[i].i][j] = !shelf[qs[i].i][j];
      }
    }
    if(save[i]){
      for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
          load[j][k] = shelf[j][k];
        }
      }
    }
  }
}

int main(){
  scanf("%d %d %d",&n,&m,&q);
  memset(save,0,sizeof save);
  memset(shelf,0,sizeof shelf);
  memset(load,0,sizeof load);
  for(int i = 0; i < q; i++){
    int op;
    scanf("%d",&op);
    if(op == 1 || op == 2){
      int a, b;
      scanf("%d %d",&a,&b);
      qs.pb(query(op,a-1,b-1));
    }
    else if(op == 3){
      int a;
      scanf("%d",&a);
      qs.pb(query(op,a));
    }
    else {
      int a;
      scanf("%d",&a);
      qs.pb(query(op,a));
      save[q] = 1;
      if(q && save[q-1]) save[q-1] = 0;
    }
  }
 
  return 0;
}
