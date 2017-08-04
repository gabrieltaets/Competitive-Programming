#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  string str;
  int sum = 0;
  while(getline(cin,str)){
    if(str[0] == 'c'){
      cout << sum << endl;
      sum = 0;
      continue;
    }
    if(str[0] == '*') sum += 4;
    if(str[1] == '*') sum += 2;
    if(str[2] == '*') sum++;
  }
  return 0;
}