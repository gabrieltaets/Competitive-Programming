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
  int n, sum = 0;
  bool chk = true;
  cin >> n;
  vi arr(n);
  for(int i = 0; i < n; i++){
    scanf("%d",&arr[i]);
    if(arr[i]) chk = false;
    sum += arr[i];
  }
  if(chk){
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if(sum){
    printf("1\n1 %d",n);
    return 0;
  }
  for(int i = n-1; i >= 0; i--){
    if(arr[i]){
      printf("2\n1 %d\n%d %d\n",i,i+1,n);
      return 0;
    }
  }
  return 0;
}
