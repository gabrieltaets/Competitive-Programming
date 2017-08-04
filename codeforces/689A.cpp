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
bool down(string str){
  for(int i = 0; i < str.size(); i++){
    if(str[i] == 7 || str[i] == 0 || str[i] == 9) return false;
  }
  return true;
}
bool up(string str){
  for(int i = 0; i < str.size(); i++){
    if(str[i] >= 1 && str[i] <= 3) return false;
  }
  return true;
}
bool left(string str){
  for(int i = 0; i < str.size(); i++){
    if(str[i] == 1 || str[i] == 4 || str[i] == 7 || str[i] == 0) return false;
  }
  return true;
}
bool right(string str){
  for(int i = 0; i < str.size(); i++){
    if(str[i] == 3 || str[i] == 6 || str[i] == 9 || str[i] == 0) return false;
  }
  return true;
}
int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); i++){
    str[i] -= '0';
  }
  bool ans = up(str) || down(str) || left(str) || right(str);
  printf("%s\n",ans?"NO":"YES");
  return 0;
}
