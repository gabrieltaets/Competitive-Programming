#include <bits/stdc++.h>
#define MAX_N 500010 // second approach: O(n log n)
using namespace std;
char T[MAX_N]; // the input string, up to 100K characters
int n; // the length of input string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int Phi[MAX_N], LCP[MAX_N], PLCP[MAX_N];
int c[MAX_N]; // for counting/radix sort

typedef unsigned long long ll;
typedef char HType;
const int P1 = 131, P2 = 131;
ll   MOD = 10000000002065383LL;
 
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
 
Hash pot[MAX_N];
vector<Hash> v;

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

void countingSort(int k) { // O(n)
  int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n
  memset(c, 0, sizeof c); // clear frequency table
  for (i = 0; i < n; i++) // count the frequency of each integer rank
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t; }
  for (i = 0; i < n; i++) // shuffle the suffix array if necessary
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++) // update the suffix array SA
    SA[i] = tempSA[i];
}

void constructSA() { // this version can go up to 100000 characters
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i]; // initial rankings
  for (i = 0; i < n; i++) SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}
  for (k = 1; k < n; k <<= 1) { // repeat sorting process log n times
    countingSort(k); // actually radix sort: sort based on the second item
    countingSort(0); // then (stable) sort based on the first item
    tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
    for (i = 1; i < n; i++) // compare adjacent suffixes
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++) // update the rank array RA
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break; // nice optimization trick
} }

void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1; // default value
  for (i = 1; i < n; i++) // compute Phi in O(n)
    Phi[SA[i]] = SA[i-1]; // remember which suffix is behind this suffix
  for (i = L = 0; i < n; i++) { // compute Permuted LCP in O(n)
    if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
    while (T[i + L] == T[Phi[i] + L]) L++; // L increased max n times
    PLCP[i] = L;
    L = max(L-1, 0); // L decreased max n times
  }
  for (i = 0; i < n; i++) // compute LCP in O(n)
    LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the correct position
}
int main() {
  bool flag = false;
  while(gets(T)!=NULL){
    set<ll> hashset;
    if(flag) printf("\n");
    flag = true;
    int n1, n2;
    n1 = (int)strlen(T); // input T as per normal, without the ‘$’
    T[n1++] = '$'; // add terminating character
    gets(T+n1);
    char flush[500];
    n2 = (int)strlen(T)-n1;
    T[n1+n2++] = '#';
    T[n1+n2] = '\0';
    n = n1 + n2;
    //cout << T << endl;
    constructSA();
    computeLCP();
    v = build_hash(n2,T+n1);
   // printf("Building hash for %s\n",T+n1);
    int maxf = -1, maxi = n1+n2+1, maxj = 0;
    for(int i = 1; i < n1 + n2; i++){
      if((SA[i] < n1 && SA[i-1] >= n1) ||  (SA[i] >= n1 && SA[i-1] < n1)){
        if(LCP[i] > maxf){
          //printf("Different owners\n");
          maxf = LCP[i];
          //printf("Found CS of length %d at %d\n",maxf,SA[i]);
        }
      }
    }
    if(maxf) {
      priority_queue <string,vector<string>,greater<string> > pq;
      pair<set<ll>::iterator,bool> p;
      for(int i = 1; i < n1 + n2; i++){
        if((SA[i] < n1 && SA[i-1] >= n1) ||  (SA[i] >= n1 && SA[i-1] < n1)){
          if(LCP[i] == maxf){ //&& SA[i-1] >= n1){
            ll x;
            int pos;
            if(SA[i-1] >= n1){
              x = (get_hash(SA[i-1]-n1,SA[i-1]-1-n1+maxf,v)).h1;
              pos = SA[i-1];
              //printf("Hash(%d,%d) of ",SA[i-1]-n1,SA[i-1]-1-n1+maxf);
              //for(int j = 0; j < maxf; j++) putchar(T[SA[i-1]+j]);
              //printf(" = %lld\n",x);

            }
            else {
             //cout << "AQUI\n";
              x = get_hash(SA[i]-n1,SA[i]-1-n1+maxf,v).h1;
              pos = SA[i];
              //printf("Hash(%d,%d) of ",SA[i]-n2,SA[i]-1-n2+maxf);
              //for(int j = 0; j < maxf; j++) putchar(T[SA[i]+j]);
             // printf(" = %lld\n",x);
            }
            p = hashset.insert(x);
            //cout << "Inserting " << string(T+pos,maxf) << endl;
            if(p.second) pq.push(string(T+pos,maxf));
          }
        }
      }
      while(pq.size() > 0){
        cout << pq.top() << endl;
        pq.pop();
      }
    }
    else printf("No common sequence.\n");
    if(gets(flush)==NULL) break;
  }
  //for (int i = 0; i < n1+n2; i++) printf("%2d %2d %2d\t%s\n", SA[i],LCP[i],(SA[i] < n1 ? 1:2), T + SA[i]);
  return 0;
} // return 0;