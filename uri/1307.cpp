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
inline int gcd(int a, int b){
  return b ? gcd(b, a % b) : abs(a);
}
int main(){
  int t;
  cin >> t;
  for(int c = 1; c <= t; c++){
    string str;
    int a, b;
    cin >> str;
    a = stoi(str,NULL,2);
    cin >> str;
    b = stoi(str,NULL,2);
    printf("Pair #%d: ",c);
    printf("%s\n",gcd(a,b)==1?"Love is not all you need!":"All you need is love!");
  }
  return 0;
}
