// Gabriel Taets - Universidade Federal de Itajubá - gabrieltaets at gmail.com
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
int tree[200100];
int n, hi = -1, lo = 0x3f3f3f3f;
int matricula[100010];
int pai[100010];

void insere(int node){
  if(tree[0] == -1){
    hi = lo = node;
    tree[0] = tree[1] = node;
    return;
  }
  int atual = 0;
  if(matricula[node] > matricula[hi]){
    int dir = hi*2+1;
    tree[dir] = node;
    pai[node] = hi;
    hi = node;
    return;
  }
  if(matricula[node] < matricula[lo]){
    int esq = lo*2;
    tree[esq] = node;
    pai[node] = lo;
    lo = node;
    return;
  }
  while(1){
    int dir = atual*2+1, esq = atual*2;
    if(matricula[node] > matricula[atual]){
      if(tree[dir] == -1){
        tree[dir] = node;
        pai[node] = atual;
        return;
      }
      atual = tree[dir];
      continue;
    }
    else {
      if(tree[esq] == -1){
        tree[esq] = node;
        pai[node] = atual;
        return;
      }
      atual = tree[esq];
      continue;
    }
  }
}

int main(){
  scanf("%d",&n);
  memset(tree,-1,sizeof tree);
  for(int i = 1; i <= n; i++){
    scanf("%d",&matricula[i]);
    insere(i);
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int x;
    scanf("%d",&x);
    if(i) putchar(' ');
    printf("%d",matricula[pai[x]]);
  }
  putchar('\n');
  return 0;
}
