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

map<char,int> val;

int todec(string str){
  int num = 0;
  for(int i = 0; i < str.size(); i++){
    switch (str[i]){
      case 'I':
      case 'X':
      case 'C':
        if(i+1 < str.size()){
          if(val[str[i+1]] > val[str[i]]) {
            num -= val[str[i]];
            break;
          }
        }
      case 'M':
      case 'D':
      case 'L':
      case 'V':
        num += val[str[i]];
        break;
    }
  }
  return num;
}

string toroman(int num){
  string str;
  while(num >= 1000){
    num -= 1000;
    str += "M";
  }
  if(num >= 900) {
    str += "CM";
    num -= 900;
  }
  if(num >= 500) {
    num -= 500;
    str += "D";
  }
  if(num >= 400) {
    num -= 400;
    str += "CD";
  }
  while(num >= 100) {
    num -= 100;
    str += "C";
  }
  if(num >= 90) {
    num -= 90;
    str += "XC";
  }
  if(num >= 50) {
    num -= 50;
    str += "L";
  }
  if(num >= 40) {
    num -= 40;
    str += "XL";
  }
  while(num >= 10) {
    num -= 10;
    str += "X";
  }
  if(num >= 9) {
    num -= 9;
    str += "IX";
  }
  if(num >= 5) {
    num -= 5;
    str += "V";
  }
  if(num >= 4) {
    num -= 4;
    str += "IV";
  }
  while(num){
    num--;
    str += "I";
  }
  return str;
}

int main(){
  val['I'] = 1;
  val['V'] = 5;
  val['X'] = 10;
  val['L'] = 50;
  val['C'] = 100;
  val['D'] = 500;
  val['M'] = 1000;
  int n, c = 1;
  while(scanf("%d",&n) && n){
    string str;
    int sum = 0;
    for(int i = 1; i <= n; i++){
      cin >> str;
      sum += todec(str);
    }
    printf("Case %s: %s\n",toroman(c++).c_str(),toroman(sum).c_str());
  }
  return 0;
}
