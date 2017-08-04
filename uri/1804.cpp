#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class FenwickTree {
 private:
  vi ft;
  int LSOne(int n){ return (n & (-n)); }
 public:
  FenwickTree(int n) {
    ft.assign(n + 1, 0);
  }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
  }
  void adjust(int k, int v) {
    for (;k < (int)ft.size(); k+=LSOne(k)) ft[k] += v;
} };
FenwickTree F(100000);
int vet[100005];
int main(){
  int N, b;
  scanf("%d",&N);
  for(int i = 1; i <= N; i++){
    scanf("%d",&vet[i]);
    F.adjust(i,vet[i]);
  }
  char op;
  while(scanf(" %c",&op)!=EOF){
    scanf("%d",&b);
    if(op == 'a') F.adjust(b,-vet[b]);
    if(op == '?') printf("%d\n",F.rsq(b-1));
  }
  return 0;
}