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
 
const int MN=1e6+35;
int SMN;
 
class mo {
public:
  int l, r, i;
  mo(){};
  mo(int _l, int _r, int _i) {
    l=_l, r=_r, i=_i;
  }
  bool operator <(mo foo) const {
    if(r/SMN!=foo.r/SMN)
      return r/SMN < foo.r/SMN;
    if(l!=foo.l)
      return l<foo.l;
    return i<foo.i;
  }
};
 
int n;
int v[MN];
int f[MN];
int p[MN];
 
int sum=0;
void update(int i, int s) {
	//printf("%s %d [freq = %d]",s>0?"Inserting":"Removing",v[i],f[v[i]]+s);
  if(f[p[i]]==0 || (f[p[i]]==1&&s==-1)){
    f[p[i]] += s;
    return;
  }
  f[p[i]] += s;
  sum ^= v[p[i]];
}

mo data[MN];
int ans[MN];
map<int,int> seen;
int main() {
  scanf("%d", &n);
  SMN = (int) 2*sqrt(n);
  memset(f,0,sizeof f);
  for(int i=1; i<=n; i++){
    scanf("%d", &v[i]);
    pair<map<int,int>::iterator,bool> pa = seen.insert(mp(v[i],i));
    if(pa.second){
      p[i] = i;
    }
    else p[i] = pa.first->second;
    //printf("i=%d v[i]=%d p[i] =%d\n",i,v[i],p[i]);
  }
  int q;
  scanf("%d", &q);
  for(int i=0; i<q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    data[i].l = l;
    data[i].r = r;
    data[i].i = i;
  }
  sort(data, data+q);
  int l, r;
  l=r=1;
  sum=0;
  update(l, 1);
  for(int i=0; i<q; i++) {
    int li=data[i].l;
    int ri=data[i].r;
    int j=data[i].i;
    while(l>li)
        update(--l, 1);
    while(r<ri)
        update(++r, 1);
    while(l<li)
        update(l++, -1);
    while(r>ri)
        update(r--, -1);
    ans[j]=sum;
  }
  for(int i=0; i<q; i++)
    printf("%d\n", ans[i]);
  return 0;
}