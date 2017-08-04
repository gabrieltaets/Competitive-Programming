#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int n, x, mi = 1000000, ma = 0, midx, maidx;
  scanf("%d",&n);
  int v[n+1];
  for(int i = 1; i <= n; i++){
    scanf("%d",&v[i]);
    if(v[i] > ma){
      ma = v[i];
      maidx = i;
    }
    if(v[i] < mi){
      mi = v[i];
      midx = i;
    }
  }
  // swap max with 1
  int dist = 0, cont = 0;
  swap(v[1],v[maidx]);
  for(int i = 1; i != midx; i++){
    dist++;
  }
  swap(v[1],v[maidx]);
  // swap max with n
  swap(v[n],v[maidx]);
  for(int i = midx; i != n; i++){
    cont++;
  }
  dist = max(dist,cont);
  swap(v[n],v[maidx]);
  // swap min with 1
  swap(v[1],v[midx]);
  cont = 0;
  for(int i = 1; i != maidx; i++){
    cont++;
  }
  dist = max(dist,cont);
  swap(v[1],v[midx]);
  // swap min with n
  swap(v[n],v[midx]);
  cont = 0; 
  for(int i = maidx; i != n; i++){
    cont++;
  }
  swap(v[n],v[midx]);
  dist = max(dist,cont);
  cout << dist << endl;
  return 0;
}