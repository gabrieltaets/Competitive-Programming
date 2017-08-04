#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int n;
  while(cin >> n){
    int i;
    for(i = 0; i <= 100; i++){
      for(int j = 0; j <= 100; j++){
        if(i*i+j*j==n){
          printf("YES\n");
          i = j = 102;
        }
      }
    }
    if(i == 101) printf("NO\n");
  }
  return 0;
}