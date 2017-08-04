#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

typedef unsigned long long ll;
typedef char HType;
const int P1 = 57, P2 = 57;
 
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

vector<Hash> v1;
vector<int> sz;
string str;
int ans;

int main(){
  getline(cin,str);
  int l = 0, r = str.size(), mid;
  v1 = build_hash(str.size(),str.c_str());
  for(int i = 0; i < str.size()-1; i++) if(str[i] == str[str.size()-1]) sz.push_back(i+1);
  r = 2*sz[sz.size()-1];
  bool debug = false;
  debug = true;
  //cout << "TESTE\n";
  if(!sz.empty()) while(l <= r){
    int i, meio = (l+r)/2;
    cout << "MEIO = " << meio << endl;
    getchar();
    //if(meio < 0 || meio >= sz.size()) break;
    bool middle = false, end = false;
    mid = meio;
    Hash h = get_hash(0,mid-1,v1);
    if(debug) cout << "Looking for \"" << str.substr(0,mid) << "\": " << h.h1 << endl;
    ll tofind = h.h1;
    
    for(i = 1; i + mid < str.size(); i++){
      if(debug) printf("i = %d  mid = %d\n",i,mid);
      h = get_hash(i,i+mid-1,v1);
      if(debug) cout << "Hashing \"" << str.substr(i,mid) << "\": " << h.h1 << endl;
      if(h.h1 == tofind) middle = true;
    }
    h = get_hash(i,i+mid-1,v1);
    if(debug) cout << "Hashing \"" << str.substr(i,mid) << "\": " << h.h1 << endl;
    if(h.h1 == tofind) end = true;
    if(middle && end){
      ans = mid;
      l = meio + 1;
    } 
    else r = meio - 1;
  }
  cout << (ans==0?(string)"Just a legend":str.substr(0,ans)) << endl;
  return 0;
}