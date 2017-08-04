#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k, p;
  while(scanf("%d %d",&n,&k)!=EOF && (n+k)){
    int freq[150];
    memset(freq,0,sizeof freq);
    for(int i = 0; i < n; i++){
      int x;
      scanf("%d",&x);
      freq[x]++;
    }
    int cont = 0;
    for(int i = 0; i < 150; i++) if(freq[i] >= k) cont++;
    cout << cont << endl;
  }
  return 0;
}
