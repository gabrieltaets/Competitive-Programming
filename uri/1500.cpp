#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define MAXN 100010
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll tr[4*MAXN];
ll lazy[4*MAXN];

void build(int node, int l, int r){
  lazy[node] = 0;
  if(l == r){
    tr[node] = 0;
    return;
  }
  build(node*2,l,(l+r)/2);
  build(node*2+1,(l+r)/2+1,r);
  tr[node] = tr[node*2]+tr[node*2+1];
}

void propagate(int node, int l, int r){
  if(!lazy[node]) return;
  tr[node] += (r-l+1)*lazy[node];
  if(l != r){
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int a, int b, ll val){
  propagate(node,l,r);
  if(a > r || b < l || l > r) return;
  if(l >= a && r <= b) {
    lazy[node] += val;
    propagate(node,l,r);
    return;
  }
  update(node*2,l,(l+r)/2,a,b,val);
  update(node*2+1,(l+r)/2+1,r,a,b,val);
  tr[node] = tr[node*2]+tr[node*2+1];
}

ll query(int node, int l, int r, int a, int b){
  propagate(node,l,r);
  if(a > r || b < l || l > r) return 0;
  if(l >= a && r <= b) {
    return tr[node];
  }
  return query(node*2,l,(l+r)/2,a,b) + query(node*2+1,(l+r)/2+1,r,a,b);  
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N, C;
    scanf("%d %d",&N,&C);
    build(1,1,N);
    while(C--){
      int a, b, c;
      ll d;
      scanf("%d",&a);
      if(!a){
        scanf("%d %d %lld",&b,&c,&d);
        update(1,1,N,b,c,d);
      }
      else {
        scanf("%d %d",&b,&c);
        printf("%lld\n",query(1,1,N,b,c));
      }
    }
  }
  return 0;
}