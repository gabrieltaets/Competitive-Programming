#include <bits/stdc++.h>
using namespace std;
int ax, ay, bx, by, tx, ty, n, pos[100010][2];

inline double distance(int xx, int xy, int yx, int yy){
  return sqrt(((double)xx-yx)*((double)xx-yx)+((double)xy-yy)*((double)xy-yy));
}

int main(){
  int mintoai = -1, maxtobi = -1, mintoai2 = -1, maxtobi2 = -1;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  cin >> n;
  double dist = 0, mintoa = -1e18, maxtob = -1e18, toa, tob, tot, mintoa2 = -1e18, maxtob2 = -1e18;
  for(int i = 0; i < n; i++){
    cin >> pos[i][0] >> pos[i][1];
    tot = distance(pos[i][0],pos[i][1],tx,ty);
    toa = distance(pos[i][0],pos[i][1],ax,ay);
    tob = distance(pos[i][0],pos[i][1],bx,by);
    dist += 2.0*tot;
    if(tot - toa > mintoa){
      mintoa2 = mintoa;
      mintoa = tot-toa;
      mintoai2 = mintoai;
      mintoai = i;
    }
    else if(tot - toa > mintoa2){
      mintoa2 = tot-toa;
      mintoai2 = i;
    }
    if(tot - tob > maxtob){
      maxtob2 = maxtob;
      maxtob = tot-tob;
      maxtobi2 = maxtobi;
      maxtobi = i;
    }
    else if(tot - tob > maxtob2){
      maxtob2 = tot-tob;
      maxtobi2 = i;
    }
  }
  if(maxtobi == mintoai){
    if(maxtob + mintoa2 > maxtob2 + mintoa){
      mintoa = mintoa2;
      mintoai = mintoai2;
    }
    else {
      maxtob = maxtob2;
      maxtobi = maxtobi2;
    }
  }
  if(mintoa > 0){
    dist -= mintoa;
    if(maxtob > 0){
      dist -= maxtob;
    }
  }
  else {
    if(maxtob > 0){
      dist -= maxtob;
    }
    else {
      if(maxtob > mintoa){
        dist -= maxtob;
      }
      else {
        dist -= mintoa;
      }
    }
  }
  printf("%.9f\n",dist);
  return 0;
}