/* Gabriel Augusto Alves Taets		*/
/* Universidade Federal de Itajuba	*/
/* gabrieltaets at gmail.com 		*/
/* github.com/gabrieltaets/ 		*/

#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef char HType;

const int P1 = 37, P2 = 53, MOD = (int)1e9+7;
struct Hash {
    ll h1, h2;
    Hash(ll a = 0, ll b = 0) { h1 = a; h2 = b; }
    void append(HType c) {
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

string s1, s2;
Hash pot[100010];
vector<Hash> v1, v2;

void build_hash() {
    pot[0] = Hash(1,1);
    Hash acc1, acc2;
    for(int i = 0; i < s1.size(); i++) {
    	acc1.append(s1[i]);
    	v1.pb(acc1);
    	if(i > 0) pot[i] = pot[i-1] * Hash(P1,P2);
    }
    for(int i = 0; i < s2.size(); i++){
    	acc2.append(s2[i]);
    	v2.pb(acc2);
    	if(i > 0) pot[i] = pot[i-1] * Hash(P1, P2);
    }
}
 
Hash get_hash(int l, int r, vector<Hash> &hashv) {
    if(l == 0) return hashv[r];
    return hashv[r] - hashv[l-1] * pot[r-l+1];
}

bool check(int x){
	Hash h1 = get_hash(0, x-1, v1), h2 = get_hash(0, x-1, v2);
	if(h1 != h2) return false;
	for(int i = x; i < s1.size(); i += x){
		Hash aux = get_hash(i, i+x-1, v1);
		if(aux != h1) return false;
	}
	for(int i = x; i < s2.size(); i += x){
		Hash aux = get_hash(i, i+x-1, v2);
		if(aux != h2) return false;
	}
	return true;
}

int main(){
	cin >> s1 >> s2;
	build_hash();
	vi c;
	for(int i = 1; i <= min(s1.size(), s2.size()); i++){
		if(s1.size()%i == 0 && s2.size()%i == 0) c.pb(i);
	}
	int ans = 0;
	for(int i = 0; i < c.size(); i++){
		if(check(c[i])) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
