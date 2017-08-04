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
  double flow[12][12];
  for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++) flow[i][j] = 0;
  flow[1][1] = 1.0;
  for(int i = 2; i <= 10; i++){
    flow[i][1] = flow[i][i] = flow[i-1][1]/2.0;
    for(int j = 2; j < i; j++){
      flow[i][j] = flow[i-1][1];
    }
  }
  int n, t, cont = 0;
  scanf("%d %d",&n,&t);
  if(!t){
    printf("0\n");
    return 0;
  }
  double glass[12][12];
  for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++) glass[i][j] = 0;
  glass[1][1] = 2.0;
  for(int k = 2; k <= t; k++){
    for(int i = 1; i < n; i++){
      for(int j = 1; j <= i; j++){
        if(glass[i][j] > 1){
          glass[i+1][j] += (glass[i][j]-1.0)/2.0;
          glass[i+1][j+1] += (glass[i][j]-1.0)/2.0;
          glass[i][j] = 1;
        }
        if(i == 1 && j == 1) glass[i][j] = 2;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      //printf("%.2f  ",glass[i][j]);
      if(glass[i][j] >= 0.999)  cont++;
    }
    //putchar('\n');
  }
  cout << cont << endl;
  return 0;
}