#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  while(n--){
    int k;
    cin >> k;
    set<string> s;
    string str;
    while(k--){
      cin >> str;
      s.insert(str);
    }
    if(s.size() > 1) printf("ingles\n");
    else cout << *s.begin() << endl;
  }
  return 0;
}