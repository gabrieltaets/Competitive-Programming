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
int trie[10000010][2];
int cont=1;

void insert(int node, int val, int p){
  //printf("node=%d,val=%d,p=%d\n",node,val,p);
  if(p < 0) return;
  int left = trie[node][0], right = trie[node][1];
  bool active = (val&(1<<p));
  if(active){
    if(right){
      insert(right,val,p-1);
    }
    else {
      trie[node][1] = ++cont;
      insert(cont,val,p-1);
    }
  }
  else {
    if(left) insert(left,val,p-1);
    else {
      trie[node][0] = ++cont;
      insert(cont,val,p-1);
    }
  }
}

int query(int val){
  int left = trie[1][0], right = trie[1][1], node = 1, p = 31;
  int ans = 0;
  while(p >= 0 && (left || right)){
    bool active = (val&(1<<p));
    if(!active){
      if(right){
      //  printf("Can get 1\n");
        ans |= (1<<p);
        node = right;
      }
      else {
       // printf("Must place 0\n");
        node = left;
      }
    }
    else {
      if(left) {
      //  printf("Can get 0\n");
        node = left;
      }
      else {
       // printf("Must place 1\n");
        ans |= (1<<p);
        node = right;
      }
    }
    p--;
    left = trie[node][0], right = trie[node][1];
  }
  //printf("\n");
  return max(val,ans^val);
}

void remove(int x){
  vi path;
  int node = 1, p = 31;
  path.pb(1);
  while(p >= 0){
    if(x&(1<<p)){
      path.pb(trie[node][1]);
      node = trie[node][1];
    }
    else {
      path.pb(trie[node][0]);
      node = trie[node][0];
    }
    p--;
  }
  for(int i = path.size()-2; i >= 0; i--){
    node = path[i];
    if(trie[node][0] == path[i+1]){
      trie[node][0] = 0;
      if(trie[node][1]) break;
    }
    else {
      trie[node][1] = 0;
      if(trie[node][0]) break;
    }
  }
}

void check(int node, int mask, int p){
  //printf("Checking node %d (mask %d, p = %d) ",node,mask,p);
  if(p < 0){
    printf("found %d\n",mask);
    return;
  }
  int left = trie[node][0], right = trie[node][1];
  //printf(" left = %d right = %d\n",left,right);
  if(left) check(left,mask,p-1);
  if(right) check(right,mask|(1<<p),p-1);
}

map<int,int> qtd;

int main(){
  memset(trie,0,sizeof trie);
  int q;
  cin >> q;
  while(q--){
    char op;
    int x;
    scanf(" %c %d",&op,&x);
    if(op == '+') {
      insert(1,x,31);
      qtd[x]++;
    }
    if(op == '?') cout << query(x) << endl;
    if(op == '-') {
      qtd[x]--;
      if(qtd[x] == 0) remove(x);
    }
    //check(1,0,31);
  }
  return 0;
}
