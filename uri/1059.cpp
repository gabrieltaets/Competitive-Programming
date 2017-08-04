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
  vi used;
  int op = 0;
  for(int z = 1; z <= 165; z++){
    for(int i = 1; i <= 100; i++){
      for(int j = i; j <= 100; j++){
        for(int k = i; k <= j; k++){
          if(k % 2 == 0){
            bool flag = false;
            for(int x = 0; x < used.size(); x++){
              if(used[x] == k) flag = true;
              op++;
            }
            if(!flag) used.pb(k);
          }
        }
      }
    } 
  }
  sort(used.begin(),used.end());
  for(int i = 0; i < used.size(); i++){
    printf("%d\n",used[i]);
  }
  return 0;
}
