#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> Vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int t[5];
  cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4];
  sort(t,t+5);
  int sum = 0;
  for(int i = 0; i < 5; i++) sum += t[i];
  int maxr = 0;
  for(int i = 0; i < 5; i++){
    int rm = 0;
    for(int j = i+1; j < i+3 && j < 5; j++){
      if(t[i] == t[j]) rm += t[i];
    }
    if(rm) rm += t[i];
    maxr = max(maxr,rm);
  }
  cout << sum-maxr << endl;
  return 0;
}
