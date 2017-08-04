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
  bool winner = true;
  scanf("%d",&n);
  while(n--){
    int a;
    scanf("%d",&a);
    if(a == 1) {
      printf("%d\n",winner+1);
      continue;
    }
    if(a%2==0) winner = !winner;
    printf("%d\n",winner+1);
  }
  return 0;
}
