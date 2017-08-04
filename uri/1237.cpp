#include <bits/stdc++.h>
#define MAXN 600
using namespace std;

typedef long long ll;
typedef char HType;
 
const int P1 = 57, P2 = 57, MOD = (int)1e9 + 7;
 
struct Hash {
    ll h1, h2;
    Hash(ll a = 0, ll b = 0) { h1 = a; h2 = b; }
    void append(int c) {
        h1 = (P1*h1 + c) % MOD;
        h2 = (P2*h2 + c) % MOD;
    }
    bool operator== (Hash that) const {
        return h1 == that.h1 && h2 == that.h2;
    }
    bool operator!= (Hash that) const {
        return h1 != that.h1 || h2 != that.h2;
    }
    Hash operator*  (Hash that) const {
        return Hash((h1*that.h1)%MOD, (h2*that.h2)%MOD);
    }
    Hash operator-  (Hash that) const {
        return Hash( (h1 - that.h1 + MOD)%MOD, (h2 - that.h2 + MOD)%MOD);
    }
    bool operator< (Hash that) const {
      if(h1 == that.h1) return h2 < that.h2;
      return h1 < that.h1;
    }
};
 
Hash pot[MAXN];
 
vector<Hash> build_hash(int n, int *v) {
    pot[0] = Hash(1,1);
    vector<Hash> ret;
    Hash acc;
    for(int i = 0; i < n; i++) {
        acc.append(v[i]);
        ret.push_back(acc);
        if(i > 0) pot[i] = pot[i-1] * Hash(P1, P2);
    }
    return ret;
}
 
inline Hash get_hash(int l, int r, vector<Hash> &hashv) {
    if(l == 0) return hashv[r];
    return hashv[r] - hashv[l-1] * pot[r-l+1];
}

int x1[600], x2[600];

int main(){
  int n;
  while(scanf("%d",&n) != EOF && n){
    for(int i = 0; i < n; i++) scanf("%d",&x1[i]);
    for(int i = 0; i < n; i++) scanf("%d",&x2[i]);
    int l = 0, r = n, mid, ans = 0;
    vector<Hash> v1, v2;
    v1 = build_hash(n,x1);
    v2 = build_hash(n,x2);
    map<long long,int> m;
    map<long long,int>::iterator it;
    while(l <= r){
      int i;
      mid = (l+r)/2;
      Hash h;
      //cout << "STRING 1\n";
      for(i = 0; i + mid <= n; i++){
        //printf("i = %d  mid = %d\n",i,mid);
        h = get_hash(i,i+mid-1,v1);
        //cout << "Hashing \"" << str.substr(i,mid) << "\": " << h.h1 << endl;
        m[h.h1] = mid;
      }
      bool flag = false;
      //cout << "STRING 2\n";
      for(i = 0; i + mid <= n; i++){
        h = get_hash(i,i+mid-1,v2);
        //cout << "Hashing \"" << str2.substr(i,mid) << "\": " << h.h1 << endl;
        it = m.find(h.h1);
        if(it != m.end()){
    //      cout << "Set ans = " << it->second << endl;
          ans = it->second;
          flag = true;
        }
      }
      if(flag) l = mid + 1;
      else r = mid - 1;
    }
    cout << ans << endl;
    //cout << ans.size() << endl;
  }
  return 0;
}