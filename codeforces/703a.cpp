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
  int M = 0, C = 0;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    if(a > b) M++;
    if(b > a) C++;
  }
  if(M > C) printf("Mishka\n");
  else if(M < C) printf("Chris\n");
  else printf("Friendship is magic!^^\n");
  return 0;
}
