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
  string n1, n2;
  cin >> n1;
  n2 = n1;
  reverse(n2.begin(),n2.end());
  cout << n1 << n2 << endl;
  return 0;
}
