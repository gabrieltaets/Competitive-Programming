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
  int len;
  cin >> len;
  int ans[len+1];
  int s1, s2, s3;
  printf("? 1 2\n");
  fflush(stdout);
  scanf("%d",&s1);
  printf("? 1 3\n");
  fflush(stdout);
  scanf("%d",&s2);
  printf("? 2 3\n");
  fflush(stdout);
  scanf("%d",&s3);
  
  ans[1] = (s1+s2-s3)/2;
  ans[3] = s2 - ans[1];
  ans[2] = s3 - ans[3];
  
  for(int i = 4; i <= len; i++){
    printf("? 1 %d\n",i);
    fflush(stdout);
    scanf("%d",&s1);
    ans[i] = s1-ans[1];
  }
  printf("!");
  for(int i = 1; i <= len; i++){
    printf(" %d",ans[i]);
  }
  printf("\n");
  fflush(stdout);
  
  return 0;
}