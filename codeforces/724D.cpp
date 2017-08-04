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

bool used[100010];
int tr[400010];
string str, ans;
int m;

void build(int node, int l, int r){
  if(l == r) tr[node] = l;
  else {
    build(node*2,l,(l+r)/2);
    build(node*2+1,(l+r)/2+1,r);
    int p1 = tr[node*2], p2 = tr[node*2+1];
    if(str[p1] == str[p2]) tr[node] = max(p1,p2);
    else tr[node] = (str[p1] > str[p2] ? p2:p1);
  }
}

int query(int node, int l, int r, int i, int j){
  if(i > r || j < l || l > r) return INF;
  if(l >= i && r <= j) return tr[node];
  int p1 = query(node*2,l,(l+r)/2,i,j);
  int p2 = query(node*2+1,(l+r)/2+1,r,i,j);
  if(p1 == INF) return p2;
  if(p2 == INF) return p1;
  if(str[p1] == str[p2]) return max(p1,p2);
  if(str[p1] > str[p2]) return p2;
  return p1;
}

int main(){
  cin >> m;
  cin >> str;
  build(1,0,str.size());
  char maxchar = 0;
  for(int i = 0; i < str.size();){
    int q = query(1,0,str.size(),i,min((int)str.size()-1,i+m-1));
    //printf("Q(%d,%d) = %d\n",i,min((int)str.size()-1,i+m-1),q);
    ans.pb(str[q]);
    used[q] = true;
    maxchar = max(maxchar,str[q]);
    if(q+m>=str.size()) break;
    i = q+1;
  }
  for(int i = 0; i < str.size(); i++){
    if(str[i] < maxchar && !used[i]){
      ans.pb(str[i]);
    }
  }
  sort(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}
