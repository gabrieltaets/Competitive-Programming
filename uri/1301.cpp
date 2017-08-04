#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define MAXN 100010
using namespace std;
typedef int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int tr[4*MAXN], A[MAXN];

void build(int node, int l, int r){
  if(l == r){
    tr[node] = (A[l]?(A[l]>0?1:-1):0);
    return;
  }
  build(node*2,l,(l+r)/2);
  build(node*2+1,(l+r)/2+1,r);
  tr[node] = tr[node*2]*tr[node*2+1];
}

void update(int node, int l, int r, int p, int val){
  if(p > r || p < l || l > r) return;
  if(l == r) {
    tr[node] = (val?(val>0?1:-1):0);    
    //printf("Updated, %d now = %d (%d)\n",l,tr[l],node);
    return;
  }
  update(node*2,l,(l+r)/2,p,val);
  update(node*2+1,(l+r)/2+1,r,p,val);
  tr[node] = tr[node*2]*tr[node*2+1];
}

int query(int node, int l, int r, int a, int b){
  if(a > r || b < l || l > r) return 1;
  if(l >= a && r <= b) {
    //printf("returning %d (%d)\n",tr[node]);
    return tr[node];
  }
  return query(node*2,l,(l+r)/2,a,b) * query(node*2+1,(l+r)/2+1,r,a,b);  
}

int main(){
  int N, K;
  while(scanf("%d %d",&N,&K)!=EOF){
    for(int i = 1; i <= N; i++){
      scanf("%d",&A[i]);
    }
    build(1,1,N);
    while(K--){
      char c;
      int a, b;
      scanf(" %c %d %d",&c,&a,&b);
      if(c == 'C'){
        update(1,1,N,a,b);
      }
      else {
        int x = query(1,1,N,a,b);
        putchar(x?(x>0?'+':'-'):'0');
      }
    }
    putchar('\n');
  }
  return 0;
}