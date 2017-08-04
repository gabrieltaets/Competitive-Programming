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
  string str;
  cin >> str;
  bool flag = true;
  for(int i = 1; i < str.size() && flag; i++){
    if(str[i] > 'Z') flag = false;
  }
  if(flag){
    for(int i = 0; i < str.size(); i++){
      str[i] = (str[i] == tolower(str[i]) ? toupper(str[i]) : tolower(str[i]));
    }
  }
  cout << str << endl;
  return 0;
}
