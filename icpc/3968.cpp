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

const double EPS = 1e-10;

inline int cmp(double x, double y=0, double tol=EPS) {
  return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}

struct point {
  int x, y;
  point(double x = 0, double y = 0): x(x), y(y) {}
  point operator +(point q) { return point(x + q.x, y + q.y); }
  point operator -(point q) { return point(x - q.x, y - q.y); }
  point operator *(double t) { return point(x * t, y * t); }
  point operator /(double t) { return point(x / t, y / t); }
  double operator *(point q) { return x * q.x + y * q.y; }
  double operator %(point q) { return x * q.y - y * q.x; }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator ==(point q) const { return cmp(q) == 0; }
  bool operator !=(point q) const { return cmp(q) != 0; }
  bool operator < (point q) const { return cmp(q) < 0; }
  bool operator <=(point q) const { return cmp(q)<=0; }
  friend ostream& operator <<(ostream& o, point p) {
    return o << "(" << p.x << ", " << p.y << ")";
  }
  static point pivot;
};

bool seg_intersect(point p, point q, point r, point s) {
  point A = q - p, B = s - r, C = r - p, D = s - q;
  int a = cmp(A % C) + 2 * cmp(A % D);
  int b = cmp(B % C) + 2 * cmp(B % D);
  if (a == 3 || a == -3 || b == 3 || b == -3) return false;
  if (a || b || p == r || p == s || q == r || q == s) return true;
  int t = (p < r) + (p < s) + (q < r) + (q < s);
  return t != 0 && t != 4;
}

struct coord {
  point a, b;
  coord (){}; 
  coord(point x, point y){
    a = x;
    b = y;
  }
  bool cross(const coord &x) const {
    return seg_intersect(a,b,x.a,x.b);
  }
};

char grid[110][110];
string word[110];
vi graph[110];
map<int,coord> mapa;
int n, m, l;

void find(int w){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == word[w][0]){
        int a, b, k;
        for(a = -1; a <= 1; a++) for(b = -1; b <= 1; b++){
          if(!a && !b) continue;
          point inc(a,b), at(i,j);
          for(k = 1; k < word[w].size(); k++){
            at = at + inc;
            if(at.x >= 0 && at.x < n && at.y >= 0 && at.y < m){
              if(word[w][k] != grid[at.x][at.y]) break;
            }
            else break;
          }
          if(k == word[w].size()) {
            mapa[w] = coord(point(i,j),at);
            return ;
          }
        }
      }
    }
  }
}

int vis[110];
void dfs(int node, int removed){
  int x;
  vis[node] = 1;
  for(int i = 0; i < graph[node].size(); i++){
    x = graph[node][i];
    if(!vis[x] && x != removed) dfs(x,removed);
  }
}

bool check(int r){
  memset(vis,0,sizeof vis);
  dfs(r==0?1:0,r);
  for(int i = 0; i < l; i++) {
    if(i == r) continue;
    if(!vis[i]) return false;
  }
  return true;
}

int main(){
  while(scanf("%d %d %d",&n,&m,&l) && (n || m || l)){
    for(int i = 0; i < 110; i++) graph[i].clear();
    for(int i = 0; i < n; i++) scanf("%s",grid[i]);
    for(int i = 0; i < l; i++){
      cin >> word[i];
      for(int j = 0; j < word[i].size(); j++) word[i][j] = toupper(word[i][j]);
      find(i);
    }
    for(int i = 0; i < l; i++){
      for(int j = i+1; j < l; j++){
        if(mapa[i].cross(mapa[j])) {
          //cout << word[i] << " crosses with " << word[j] << endl;
          graph[i].pb(j);
          graph[j].pb(i);
        }
      }
    }
    int i;
    for(i = 0; i < l; i++){
      if(!check(i)){
        //cout << "Can't remove " << word[i] << endl;
        break;        
      }
    }
    if(i == l){
      printf("Yes\n");
    }
    else {
      printf("No\n");
    }
  }
  return 0;
}
