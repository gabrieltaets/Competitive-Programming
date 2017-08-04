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

char grid[4][4];

bool checkHor(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 2; j++){
      int cx = 0, cd = 0;
      for(int k = 0; k < 3; k++){
        if(grid[i][j+k] == 'x') cx++;
        if(grid[i][j+k] == '.') cd++;
      }
      if(cx >= 2 && cx+cd == 3) {
        //printf("true at %d %d\n",i,j);
        return true;
      }
    }
  }
  return false;
}

bool checkVer(){
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 4; j++){
      int cx = 0, cd = 0;
      for(int k = 0; k < 3; k++){
        if(grid[i+k][j] == 'x') cx++;
        if(grid[i+k][j] == '.') cd++;
      }
      if(cx >= 2 && cx+cd == 3) {
        //printf("true at %d %d\n",i,j);
        return true;
      }
    }
  }
  return false;
}

bool checkDiag1(){
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      int cx = 0, cd = 0;
      for(int k = 0; k < 3; k++){
        if(grid[i+k][j+k] == 'x') cx++;
        if(grid[i+k][j+k] == '.') cd++;
      }
      if(cx >= 2 && cx+cd == 3) {
        //printf("true at %d %d\n",i,j);
        return true;
      }
    }
  }
  return false;
}

bool checkDiag2(){
  for(int i = 2; i < 4; i++){
    for(int j = 0; j < 2; j++){
      int cx = 0, cd = 0;
      for(int k = 0; k < 3; k++){
        if(grid[i-k][j+k] == 'x') cx++;
        if(grid[i-k][j+k] == '.') cd++;
      }
      if(cx >= 2 && cx+cd == 3) {
        //printf("true at %d %d\n",i,j);
        return true;
      }
    }
  }
  return false;
}

int main(){
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) grid[i][j] = getchar();
    getchar();
  }
  if(checkHor() || checkVer() || checkDiag1() || checkDiag2()) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
