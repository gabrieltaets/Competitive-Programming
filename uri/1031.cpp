#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int Josephus(int n, int k){
 if(k == 1)return n-1;
 if(k == 2){
 int j = floor(log10(n)/log10(2.0));
 n &= ~(1<<j);
 n = n<<1;
 n|=1;
 return n-1;
 }
 if(n==1)return 0;
 return (Josephus(n-1,k)+k)%n;
}


int main(){
  int n;
  while(cin >> n && n){
    for(int i = 1; i < 1000; i++){
      if(Josephus(n-1,i) == 11){
        printf("%d\n",i);
        break;
      }
    }
  }
  return 0;
}