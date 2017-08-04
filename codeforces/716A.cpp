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
  int c, n;
  scanf("%d %d",&n,&c);
  int qtd = 0, t = 0;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    if(x-t > c) qtd = 1;
    else qtd++;
    t = x;
  }
  cout << qtd << endl;
  return 0;
}
