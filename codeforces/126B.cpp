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
#define MAXN 1000010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef char HType;
const int P1 = 57, P2 = 57;
 
struct Hash {
    ull h1, h2;
    Hash(ull a = 0, ll b = 0) { h1 = a; h2 = b; }
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
string str,ans;

int main(){
	getline(cin,str);
	v1 = build_hash(str.size(),str.c_str());
	for(int i = 0; i < str.size()-1; i++) if(str[0] == str[str.size()-i-1]) sz.pb(i+1);
	int l = 0, r = sz.size()-1, ans = 0, mid;
	if(!sz.empty()) while(l <= r){
	  	mid = (l+r)/2;
	  	int x = 0;
	  	int len = sz[mid];
	  	//printf("checking for length %d\n",len);
		if(get_hash(0, len-1, v1) == get_hash(str.size()-len, str.size()-1, v1)){
			for(int i = 1; i + len < str.size(); i++){
				if(get_hash(0,len-1, v1) == get_hash(i, i+len-1, v1)){
					x = len;
					break;
				}
			}
		}
		if(x == len){
			//printf("sucess\n");
			ans = len;
			l = mid+1;
		}
		else r = mid-1;
	}
	printf("%s\n",ans?str.substr(0,ans).c_str():"Just a legend");
  	return 0;
}