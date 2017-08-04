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
  char *st[7] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
  char s1[32], s2[32];
  while(scanf("%s%s",s1,s2)!=EOF){
    int i, j;
    for(i = 0; i < 7; i++){
      if(strcmp(s1,st[i])==0) break;
    }
    for(j= 0; j < 7; j++){
      if(strcmp(s2,st[j])==0) break;
    }
    if(i > j) j += 7;
    if((j-i == 0) || (j - i == 2) || (j-i == 3)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
