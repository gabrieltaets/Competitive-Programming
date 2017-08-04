#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int K, N;
    scanf("%d %d",&N,&K);
    string str;
    cin >> str;
    int cancut = 0, cuts = 0;
    for(int j = 0; j < N; j = cancut+1){
      cancut = j;
      for(int i = j+1; i < min(j+K,N); i++){
        if(str[i-1] == str[i] || cancut != j) cancut = i;
      }
      cuts++;
    }
    printf("%d\n",cuts-1);
  }
  return 0;
}
