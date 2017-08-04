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

class UnionFind { 
 private:
  vi p, rank; 
 public:
  UnionFind(int N) { 
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }
	int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
	bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
	void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { 
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) p[y] = x; 
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
} } } };

int n;
int arr[100010];
ll acum[100010];
bool destr[100010];
map<int,ll> sum;
int main(){
  scanf("%d",&n);
  UnionFind UF(n+2);
  for(int i = 1; i <= n; i++){
    scanf("%d",&arr[i]);
    acum[i] = acum[i-1]+arr[i];
  }
  memset(destr,true,sizeof destr);
  stack<int> q;
  stack<ll> ans;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    q.push(x);
  }
  ll r = 0;
  while(!q.empty()){
    int x = q.top(); q.pop();
    destr[x] = false;
    ans.push(r);
    if(!destr[x+1] && !destr[x-1]) {
      int s1 = UF.findSet(x-1), s2 = UF.findSet(x+1);
      ll sum1 = sum[s1], sum2 = sum[s2];
      UF.unionSet(x-1,x);
      UF.unionSet(x+1,x);
      sum[UF.findSet(x)] = sum1+sum2+arr[x];
     // printf("Joined both, sum %lld\n",sum1+sum2+arr[x]);
    }
    else if(!destr[x-1]){
      ll sum1 = sum[UF.findSet(x-1)]+arr[x];
      UF.unionSet(x-1,x);
      sum[UF.findSet(x)] = sum1;
      //printf("Joined down, sum %lld\n",sum1);
    }
    else if(!destr[x+1]){
      ll sum1 = sum[UF.findSet(x+1)] + arr[x];
      //printf("Joined up, sum %lld\n",sum1);
      UF.unionSet(x+1,x);
      sum[UF.findSet(x)] = sum1;
      //cout << UF.findSet(x+1) << " " << UF.findSet(x) << ": Sets\n";
    }
    else {
      sum[UF.findSet(x)] = arr[x];
    }
    //cout << "Restored position " << x << " setsum = " << sum[UF.findSet(x)] << endl;
    r = max(r,sum[UF.findSet(x)]);
  }
  while(!ans.empty()){
    cout << ans.top() << endl;
    ans.pop();
  }
  return 0;
}

