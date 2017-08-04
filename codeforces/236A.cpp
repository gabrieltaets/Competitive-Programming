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
  char c;
  set<char> s;
  while(scanf("%c",&c) && c != '\n'){
    s.insert(c);
  }
  if((int)s.size()&1) printf("IGNORE HIM!\n");
  else printf("CHAT WITH HER!\n");
  return 0;
}
