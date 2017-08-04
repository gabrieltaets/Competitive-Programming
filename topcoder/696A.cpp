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

class Ropestring {
 public:
  string makerope(string s){
    vi ropespair, ropesodd;
    int sz = 0, i;
    for(i = 0; i < s.size(); i++){
      if(s[i] == '-'){
        sz++;
        break;
      }
    }
    for(i++; i < s.size(); i++){
      if(s[i] == '.' && sz){
        if(sz%2) ropesodd.pb(-sz);
        else ropespair.pb(-sz);
        sz = 0;
      }
      else if(s[i] == '-') sz++;
    }
    if(sz) {
      if(sz%2) ropesodd.pb(-sz);
      else ropespair.pb(-sz);
    }
    sort(ropespair.begin(),ropespair.end());
    sort(ropesodd.begin(),ropesodd.end());
    string ans;
    for(int i = 0; i < ropespair.size(); i++){
      ans += string(-ropespair[i],'-') + ".";
    }
    for(int i = 0; i < ropesodd.size(); i++){
      ans += string(-ropesodd[i],'-') + ".";
    }
    while(ans.size() < s.size()) ans.pb('.');
    return ans.substr(0,s.size());
  }
};
