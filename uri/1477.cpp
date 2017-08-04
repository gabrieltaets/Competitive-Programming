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

struct St {
  ll rato;
  ll elefante;
  ll humano;
  St(){
    elefante = rato = 0;
    humano = 1;
  }
  St(ll h, ll e, ll r){
    humano = h, elefante = e, rato = r;
  }
  St operator+ (const St &x) {
    St n;
    n.rato = rato + x.rato;
    n.elefante = elefante + x.elefante;
    n.humano = humano + x.humano;
    return n;
  }
  void operator+ (ll x) {
    x %= 3;
    while(x--){
      swap(elefante,humano);
      swap(humano,rato);
    }
  }
};

St tr[4*MAXN];
ll lazy[4*MAXN];

void build(int node, int l, int r){
  lazy[node] = 0;
  if(l == r){
    tr[node] = St(1,0,0);
    return;
  }
  build(node*2,l,(l+r)/2);
  build(node*2+1,(l+r)/2+1,r);
  tr[node] = tr[node*2]+tr[node*2+1];
}

void propagate(int node, int l, int r){
  if(!lazy[node]) return;
  tr[node] + lazy[node];
  if(l != r){
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int a, int b){
  propagate(node,l,r);
  if(a > r || b < l || l > r) return;
  if(l >= a && r <= b) {
    lazy[node]++;
    propagate(node,l,r);
    return;
  }
  update(node*2,l,(l+r)/2,a,b);
  update(node*2+1,(l+r)/2+1,r,a,b);
  tr[node] = tr[node*2]+tr[node*2+1];
}

St query(int node, int l, int r, int a, int b){
  propagate(node,l,r);
  if(a > r || b < l || l > r) return St(0,0,0);
  if(l >= a && r <= b) {
    return tr[node];
  }
  return query(node*2,l,(l+r)/2,a,b) + query(node*2+1,(l+r)/2+1,r,a,b);  
}

int main(){
  int N, M;
  while(scanf("%d %d",&N,&M)!=EOF){
    build(1,1,N);
    while(M--){
      char c;
      int a, b;
      scanf(" %c %d %d",&c,&a,&b);
      if(c == 'M'){
        update(1,1,N,a,b);
      }
      else {
        St x = query(1,1,N,a,b);
        printf("%d %d %d\n",x.humano,x.elefante,x.rato);
      }
    }
    putchar('\n');
  }
  return 0;
}