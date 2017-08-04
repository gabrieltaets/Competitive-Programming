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
  int n, t;
  cin >> n >> t;
  string str;
  cin >> str;
  int bpos = -1, point = -1;
  for(int i = 0; i < str.size(); i++){
    if(point==-1 && str[i] != '.') continue;
    if(str[i] == '.'){
      point = i;
      continue;
    }
    if(str[i] >= '5') {
      bpos = i;
      break;
    }
  }
  if(bpos == -1){
    cout << str << endl;
    return 0;
  }
  int op = 0;
  str = str.substr(0,bpos+1);
  for(int i = bpos; i > point+1; i--){
    if(str[i] >= '5'){
      str[i] = '0';
      str[i-1]++;
      op++;
    }
    if(op == t) break;
  }
  if(str[point+1] >= '5' && op < t){
    str[point+1] = '0';
    str[point-1]++;
    op++;
    for(int i = point-1; i > 0; i--){
      if(str[i] > '9'){
        str[i] = '0';
        str[i-1]++;
      }
    }
  }
  if(str[0] > '9') {
    str[0] = '0';
    str.insert(str.begin(),'1');
    point++;
  }
  for(int i = str.size()-1; i >= point; i--){
    if(str[i] != '0'){
      str = str.substr(0,i==point?i:i+1);
      break;
    }
  }
  cout << str << endl;
  return 0;
}
