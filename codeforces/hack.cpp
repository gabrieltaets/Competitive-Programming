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
  int a=sqrt(n);
  int flag = 0;
  for(int i = a; i <= n; i++){
    for(int j = 1; i*j <= n; j++){
      if(i*j==n){
        if(i <j){
          cout << i << " " << j << endl;
        }
        else cout << j << " " << i << endl;
        flag=1;
        break;
      }
    }
    if(flag) break;
  }
	return 0;
}
