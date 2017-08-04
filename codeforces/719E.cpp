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

#define MAXN 2
#define MOD 1000000007

struct Matriz;
Matriz matMul(Matriz,Matriz);
Matriz matPow(Matriz,int);

struct Matriz { 
  int mat[MAXN][MAXN];
  Matriz(bool identidade = false){
    if(identidade){
      for(int i = 0; i < MAXN; i++) 
        for(int j = 0; j < MAXN; j++) 
          if(i == j) mat[i][j] = 1; 
          else mat[i][j] = 0;
    }
    else {
      for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
          mat[i][j] = 1;
      mat[0][0] = 0;
    }
  }
  Matriz operator+(const Matriz &x){
    Matriz ans;
    for(int i = 0; i < MAXN; i++){
      for(int j = 0; j < MAXN; j++){
        ans.mat[i][j] = mat[i][j]+x.mat[i][j];
      }
    }
    return ans;
  }
  Matriz operator*(int x){
    Matriz ans = *this;
    for(int i = 0; i < MAXN; i++){
      for(int j = 0; j < MAXN; j++){
        ans.mat[i][j] *= x;
      }
    }
    return ans;
  }
  bool isIdentity(){
    Matriz id(true);
    for(int i = 0; i < MAXN; i++){
      for(int j = 0; j < MAXN; j++){
        if(mat[i][j] != id.mat[i][j]) return false;
      }
    }
    return true;
  }
  Matriz operator*(const Matriz &x){
    return matMul(*this,x);
  }
};

Matriz matMul(Matriz a, Matriz b) { 
  Matriz ans; int i, j, k;
  for (i = 0; i < MAXN; i++)
    for (j = 0; j < MAXN; j++)
      for (ans.mat[i][j] = k = 0; k < MAXN; k++){
        ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j])%MOD;
        ans.mat[i][j] %= MOD;
      }
  return ans; 
}

Matriz matPow(Matriz base, int p) { 
  Matriz ans; int i, j;
  for (i = 0; i < MAXN; i++) for (j = 0; j < MAXN; j++)
    ans.mat[i][j] = (i == j);
  while (p) {
    if (p & 1) ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }
  return ans; 
}

int fibMat(int n){
  Matriz f, ans;
  f.mat[0][0] = f.mat[0][1] = f.mat[1][0] = 1;
  f.mat[1][1] = 0;
  ans = matPow(f,n);
  return ans.mat[0][1];
}
int A[100010];

Matriz tr[4*MAXN][2];
Matriz lazy[4*MAXN];

void build(int node, int l, int r){
  lazy[node] = Matriz(true);
  if(l == r){
    tr[node][0] = matPow(Matriz(),A[l]);
    tr[node][1] = matPow(Matriz(),A[l]+1);
    return;
  }
  build(node*2,l,(l+r)/2);
  build(node*2+1,(l+r)/2+1,r);
  tr[node][0] = tr[node*2][0]+tr[node*2+1][0];
  tr[node][1] = tr[node*2][1]+tr[node*2+1][1];
}

void propagate(int node, int l, int r){
  if(lazy[node].isIdentity()) return;
  tr[node][0] = tr[node][0] * (lazy[node]*(r-l+1));
  tr[node][1] = tr[node][1] * (lazy[node]*(r-l+1));
  if(l != r){
    lazy[node*2] = lazy[node*2] * lazy[node];
    lazy[node*2+1] = lazy[node*2+1] * lazy[node];
  }
  lazy[node] = Matriz(true);
}

void update(int node, int l, int r, int a, int b, ll val){
  propagate(node,l,r);
  if(a > r || b < l || l > r) return;
  if(l >= a && r <= b) {
    lazy[node] = lazy[node]*val;
    propagate(node,l,r);
    return;
  }
  update(node*2,l,(l+r)/2,a,b,val);
  update(node*2+1,(l+r)/2+1,r,a,b,val);
  tr[node][0] = tr[node*2][0]*tr[node*2+1][0];
  tr[node][1] = tr[node*2][1]*tr[node*2+1][1];
}

void update(int l, int r, int x){
  for(int i = l ; i <= r; i++) A[i] += x;
}
int query(int l, int r){
  int sum = 0;
  for(int i = l; i <= r; i++){
    sum = (sum + fibMat(A[i]))%MOD;
  }
  return sum;
}
int main(){
  int n, m;
  scanf("%d %d",&n,&m);
  for(int i = 1; i <= n; i++){
    scanf("%d",&A[i]);
  }
  
  for(int i = 0; i < m; i++){
    int tp, l, r, x;
    scanf("%d %d %d",&tp,&l,&r);
    if(tp == 2){
      printf("%d\n",query(l,r));
    }
    else {
      scanf("%d",&x);
      update(l,r,x);
    }
  }
  return 0;
}
