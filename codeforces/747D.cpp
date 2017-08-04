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

int n, k;
int t[200035];

int main(){
  cin >> n >> k;
  int qtn = 0;
  vii hole;
  bool first = false;
  int cont = 0, swaps = 0;
  for(int i = 0; i < n; i++){
    scanf("%d",&t[i]);
    if(t[i] < 0) {
      if(!i || t[i-1] >= 0) swaps++;
      if(cont){
        hole.pb({0,cont});
      }
      cont = 0;
      first = true;
      qtn++;
    }
    else if(first){
      cont++;
    }
    if(t[i] >= 0){
      if(i && t[i-1] < 0) swaps++;
    }
  }
  if(cont) hole.pb({1,cont});
  if(qtn > k){
    printf("-1\n");
    return 0;    
  }
  int avlb = k-qtn;
  sort(hole.begin(),hole.end());
  for(int i = 0; i < hole.size(); i++){
    if(hole[i].S <= avlb){
      avlb -= hole[i].S;
      swaps -= (hole[i].F?1:2);
    }
  }
  cout << swaps << endl;
  return 0;
}
