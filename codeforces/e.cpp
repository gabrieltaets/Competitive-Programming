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
int g, runes, rings;
vi condition[105];
int check(int bmask){
  int cont = 0;
  for(int i = 0; i < runes; i++){
    for(int j = 0; j < 3; j++){
      bool spinning;
      if(condition[i][j] > 0){
        spinning = (bmask & (1 << condition[i][j]));
        if(spinning) {
          cont++;
          break;
        }
      }
      else {
        spinning = (bmask & (1 << abs(condition[i][j])));
        if(!spinning){
          cont++;
          break;
        }
      }
    }
  }
  return cont;
}
int main(){
  cin >> g;
  while(g--){
    cin >> rings >> runes;
    int err = 0;
    for(int i = 0; i < 105; i++) condition[i].clear();
    for(int i = 0; i < runes; i++){
      int r;
      for(int j = 0; j < 3; j++){
        cin >> r;
        condition[i].pb(r);
        if(!r) err = max(err,3); // NULL
        if(r < -rings || r > rings) err = max(err,2); // MISSING
      }
      cin >> r;
      if(abs(condition[i][0]) == abs(condition[i][1]) || abs(condition[i][0]) == abs(condition[i][2]) || abs(condition[i][1]) == abs(condition[i][2])) err = max(err,1);
    }
    if(err == 1) cout << "INVALID: RUNE CONTAINS A REPEATED RING" << endl;
    else if(err == 2) cout << "INVALID: RING MISSING" << endl;
    else if(err == 3) cout << "INVALID: NULL RING" << endl;
    else {
      int bmask, ans;
      for(bmask = 0; bmask < (1<<rings+1); bmask++){
        ans = check(bmask);
        if(ans == runes) break;
      }
      if(ans == runes) printf("RUNES SATISFIED!\n");
      else printf("RUNES UNSATISFIABLE! TRY ANOTHER GATE!\n");
    }
  }
  return 0;
}
