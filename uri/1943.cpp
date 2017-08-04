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
  int V[] = {1, 3, 5, 10, 25, 50, 100};
  int n;
  cin >> n;
  int *it = lower_bound(V,V+7,n);
  cout << "Top " << *it << endl;
  return 0;
}
