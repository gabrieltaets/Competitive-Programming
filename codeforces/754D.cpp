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

int main(){
  int n, k;
  cin >> n >> k;
  vii q(n);
  map<ii,int> interval;
  for(int i = 0; i < n; i++){
    cin >> q[i].F >> q[i].S;
    ii itv = q[i];
    interval[itv] = 0;
    for(map<ii,int>::iterator it = interval.begin(); it != interval.end(); it++){
      if((itv.F >= it->F.F || itv.S <= it->F.S) && (max(itv.F,it->F.F) <= min(itv.S,it->F.S))){
        interval[ii(max(itv.F,it->F.F),min(itv.S,it->F.S))]++;
        printf("%d %d = %d\n",max(itv.F,it->F.F),min(itv.S,it->F.S),interval[ii(max(itv.F,it->F.F),min(itv.S,it->F.S))]);
      }
    }
  }
  
  printf("\n");
  printf("INTERVALS\n");
  for(map<ii,int>::iterator it = interval.begin(); it != interval.end(); it++){
    printf("[%d, %d] = %d\n",it->F.F, it->F.S, it->S);
  }
  
  pair<int,ii> m = {0,{0,0}};
  for(map<ii,int>::iterator it = interval.begin(); it != interval.end(); it++){
    if(it->S >= k && it->F.S - it->F.F + 1 >= m.S.S - m.S.F + 1){
      m = {it->S, {it->F.F, it->F.S}};
    }
  }
  if(m.F < k){
    printf("0\n");
    for(int i = 1; i <= k; i++){
      printf("%d ",i);
    }
    printf("\n");
    return 0;
  }
  printf("%d\n",m.S.S-m.S.F+1);
  int cont = 0;
  for(int i = 0; i < n; i++){
    if(cont == k) break;
    if(m.S.F >= q[i].F && m.S.S <= q[i].S){
      printf("%d ",i+1);
      cont++;
    }
  }
  printf("\n");
  return 0;
}
