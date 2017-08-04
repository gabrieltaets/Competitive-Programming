#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;
 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}
 
const int N = 61;
 
/*
int pd[N][1 << N];
 
int func(int pos, int mask) {
  if(pd[pos][mask] != -1) return pd[pos][mask];
  if(pos == 0) return 0;
  set<int>s;
  for(int i = 1; i <= pos; ++i) {
    if((mask >> i) & 1) continue;
    s.insert(func(pos - i, mask | (1 << i)));
  }
  set<int>::iterator it = s.begin();
  int at = 0;
  while(it != s.end() && *it == at) it++, at++;
  return pd[pos][mask] = at;
}
*/
 
int nim[N];
 
int main() {
  int lol = 2;
  int q = 2;
  int at = 1;
  for(int i = 1; i <= 60; ++i) {
    nim[i] = at;
    q--;
    if(q == 0) {
      lol++;
      q = lol;
      at++;
    }
  }
  int n; scanf("%d", &n);
  int foo = 0;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    foo ^= nim[x];
  }
  puts(!foo ? "YES" : "NO");
  return 0;
}