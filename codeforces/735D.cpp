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

int n;

bool isPrime(int x){
  if(x == 2) return true;
  if(!(x&1)) return false;
  for(int i = 3; i <= ceil(sqrt(x)); i+=2){
    if(x%i==0) return false;
  }
  return true;
}

int solve(int x, bool f){
  int sum = 1;
  if(isPrime(x)) return 1;
  for(int i = x - (f?2:0); i >= 2; i--){
    if(isPrime(i)){
      if(x-i == 1){
        cout << 2 << endl;
        sum = solve(x-2,false)+1;
      }
      else {
        cout << i << endl;
        sum = solve(x-i,false)+1;
      }
      break;
    }
  }
  return sum;
}

int main(){
  int n, cont = 1;
  cin >> n;
  cout << solve(n,true) << endl;  
	return 0;
}
