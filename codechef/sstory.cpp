#include <bits/stdc++.h>
#define MAXN 250010
using namespace std;

typedef unsigned long long ll;
typedef char HType;
const int P1 = 131, P2 = 131;
 
struct Hash {
    ll h1, h2;
    Hash(ll a = 0, ll b = 0) { h1 = a; h2 = b; }
    void append(HType c) {
        h1 = (P1*h1 + c);
        h2 = (P2*h2 + c);
    }
    bool operator== (Hash that) const {
        return h1 == that.h1 && h2 == that.h2;
    }
    bool operator!= (Hash that) const {
        return h1 != that.h1 || h2 != that.h2;
    }
    Hash operator*  (Hash that) const {
        return Hash((h1*that.h1), (h2*that.h2));
    }
    Hash operator-  (Hash that) const {
        return Hash( (h1 - that.h1), (h2 - that.h2));
    }
    bool operator< (Hash that) const {
      if(h1 == that.h1) return h2 < that.h2;
      return h1 < that.h1;
    }
};
 
Hash pot[MAXN];
 
vector<Hash> build_hash(int n, const HType *v) {
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
 
Hash get_hash(int l, int r, vector<Hash> &hashv) {
    if(l == 0) return hashv[r];
    return hashv[r] - hashv[l-1] * pot[r-l+1];
}

vector<Hash> v1, v2;
map<ll,pair<int,int> > m;
map<ll,pair<int,int> >::iterator it;
string str, str2;
pair<int,int> ans(0,0);

int main(){
  getline(cin,str);
  getline(cin,str2);
  int l = 0, r = str.size(), mid;
  v1 = build_hash(str.size(),str.c_str());
  v2 = build_hash(str2.size(),str2.c_str());
  while(l <= r){
    int i;
    mid = (l+r)/2;
    Hash h;
    //cout << "STRING 1\n";
    for(i = 0; i + mid <= str.size(); i++){
      //printf("i = %d  mid = %d\n",i,mid);
      h = get_hash(i,i+mid-1,v1);
      //cout << "Hashing \"" << str.substr(i,mid) << "\": " << h.h1 << endl;
      m[h.h1] = make_pair(i,mid);
    }
    bool flag = false;
    //cout << "STRING 2\n";
    for(i = 0; i + mid <= str2.size(); i++){
      h = get_hash(i,i+mid-1,v2);
      //cout << "Hashing \"" << str2.substr(i,mid) << "\": " << h.h1 << endl;
      it = m.find(h.h1);
      if(it != m.end()){
  //      cout << "Set ans = " << it->second << endl;
        ans = it->second;
        flag = true;
        break;
      }
    }
    if(flag) l = mid + 1;
    else r = mid - 1;
  }
  if(ans.second > 0) cout << str.substr(ans.first,ans.second) << endl;
  cout << ans.second << endl;
  return 0;
}