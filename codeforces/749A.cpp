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
  int n;
  cin >> n;
  printf("%d\n",n/2);
  if(n&1){
    for(int i = 0; i < (n-3)/2; i++){
      printf("2 ");
    }
    printf("3\n");
  }
  else {
    for(int i = 0; i < n/2; i++){
      printf("2 ");
    }
    printf("\n");
  }
  return 0;
}
