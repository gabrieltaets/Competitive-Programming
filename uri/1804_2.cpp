#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define MAXN 100010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct St {
  int rato;
  int elefante;
  int humano;
  St(){
    elefante = rato = 0;
    humano = 1;
  }
  St operator+ (const St &x) const {
    St n;
    n.rato = rato + x.rato;
    n.elefante = elefante + x.elefante;
    n.humano = humano + x.humano;    
  }
};

int tr[4*MAXN], A[MAXN];
int lazy[4*MAXN];

void build(int node, int l, int r){
  if(l == r){
    tr[node] = A[l];
    return;
  }
  build(node*2,l,(l+r)/2);
  build(node*2+1,(l+r)/2+1,r);
  tr[node] = tr[node*2]+tr[node*2+1];
}

void update(int node, int l, int r, int a, int b, int val){
  if(a > r || b < l || l > r) return;
  if(l == r) {
    tr[node] += val;
    return;
  }
  update(node*2,l,(l+r)/2,a,b,val);
  update(node*2+1,(l+r)/2+1,r,a,b,val);
  tr[node] = tr[node*2]+tr[node*2+1];
}

St query(int node, int l, int r, int a, int b){
  if(l > b || r < a || l > r) return 0;
  if(l >= a && r <= b) return tr[node];
  return query(node*2,l,(l+r)/2,a,b) + query(node*2+1,(l+r)/2+1,r,a,b);  
}

int main(){
  int N, b;
  scanf("%d",&N);
  for(int i = 1; i <= N; i++){
    scanf("%d",&A[i]);
  }
  build(1,1,N);
  char op;
  while(scanf(" %c",&op)!=EOF){
    scanf("%d",&b);
    if(op == 'a') update(1,1,N,b,b,-A[b]);
    if(op == '?') printf("%d\n",query(1,1,N,1,b-1));
  }
  return 0;
}