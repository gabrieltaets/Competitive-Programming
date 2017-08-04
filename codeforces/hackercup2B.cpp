#include <bits/stdc++.h>
using namespace std;
double pd[5000][21], c;
int fat[30];
double P(int s, int i){
  int j;
  double sum = 0;
  //printf("s = %d i = %d\n",s,i);
  if(pd[s][i] >= 0) return pd[s][i];
  if(i == 0 && s == 0) return pd[s][i] = 1;
  else if(s == 0) return pd[s][i] = 0;
  for(j = 0; j <= i; j++){
    sum += (P(s-1,j)*(double)(fat[20-j]/(fat[i-j]*fat[20-i]))*pow(c,(double)i-j)*pow(1.0-c,20.0-i));
    printf("s=%d, i=%d, P=%lf, C=%lf, sum=%lf\n",s,i,P(s-1,j),(double)(fat[20-j]/(fat[i-j]*fat[20-i])),sum);
  }  
  return pd[s][i] = sum;
}
double Q(int i){
  return P(i,20) - P(i-1,20);
}

int main(){
  int T;
  fat[0] = 1;
  for(int i = 1; i < 30; i++) fat[i] = i * fat[i-1];
  cin >> T;
  for(int k = 1; k <= T; k++){
    for(int i = 0; i < 5000; i++) for(int j = 0; j < 21; j++) pd[i][j] = -1;
    scanf("%lf",&c);
    double ans = 0;
    for(int i = 1; i < 5000; i++){
      ans += (i*Q(i));
    }
    printf("Case #%d: %.5lf\n",k,ans);
  }
  return 0;
}