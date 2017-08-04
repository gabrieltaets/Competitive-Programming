#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  ii photo1[3], photo2[3];
  for(int i = 0; i < 3; i++)
    scanf("%d %d",&photo1[i].F,&photo1[i].S);
  for(int i = 0; i < 3; i++)
    scanf("%d %d",&photo2[i].F,&photo2[i].S);
  vector<int> dist1, dist2;
  for(int i = 0; i < 3; i++) for(int j = i+1; j < 3; j++){
    dist1.push_back((photo1[i].F-photo1[j].F)*(photo1[i].F-photo1[j].F)+(photo1[i].S-photo1[j].S)*(photo1[i].S-photo1[j].S));
    dist2.push_back((photo2[i].F-photo2[j].F)*(photo2[i].F-photo2[j].F)+(photo2[i].S-photo2[j].S)*(photo2[i].S-photo2[j].S));
  }
  sort(dist1.begin(),dist1.end());
  sort(dist2.begin(),dist2.end());
  for(int i = 1; i < 3; i++){
    if(dist1[i]*dist2[0] != dist2[i]*dist1[0]){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
