#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> Vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int mid, lo = 1, hi = 1000000;
  while(lo != hi){
    string str;
    mid = ((lo+hi+1)>>1);
    cout << mid << endl << flush;
    cin >> str;
    if(str == "<") hi = mid-1;
    else lo = mid;
  }
  printf("! %d\n",lo);
  return 0;
}
