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
  int n, b, d, cont = 0, w = 0;
  scanf("%d %d %d",&n,&b,&d);
  for(int i = 0; i < n; i++){
    int a;
    scanf("%d",&a);
    if(a > b) continue;
    w += a;
    if(w > d){
      w = 0;
      cont++;
    }
  }
  cout << cont << endl;
  return 0;
}
