#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int n, h;
  cin >> n >> h;
  int width = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x > h) width+=2;
    else width++;
  }
  cout << width << endl;
  return 0;
}