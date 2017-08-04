#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
  int J, R, turn = 0;
  cin >> J >> R;
  int player[J];
  memset(player,0,sizeof player);
  int maxp = -1, maxj = -1;
  for(int i = 0; i < J*R; i++){
    turn = i % J;
    int x;
    cin >> x;
    player[turn] += x;
    if(player[turn] >= maxp){
      maxp = player[turn];
      maxj = turn+1;
    }
  }
  cout << maxj << endl;
  
  return 0;
}
