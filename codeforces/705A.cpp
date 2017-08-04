#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    if(i > 1) printf(" that ");
    if(i&1){
      printf("I hate");
    }
    else {
      printf("I love");
    }
  }
  printf(" it\n");
  return 0;
}
