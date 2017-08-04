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
  int a[n];
  int m = 1;
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  sort(a,a+n);
  for(int i = 0; i < n; i++){
    if(a[i] >= m) m++;
  }
  cout << m << endl;
  return 0;
}
