#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  string n;
  int fat[6] = {1, 1, 2, 6, 24, 120};
  while(cin >> n && n[0] != '0'){
    reverse(n.begin(),n.end());
    int sum = 0;
    for(int i = 0; i < n.size(); i++){
      sum += (n[i]-'0')*fat[i+1];
    }
    cout << sum << endl;
  }
  return 0;
}