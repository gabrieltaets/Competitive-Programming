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
  int n;
  scanf("%d",&n);
  string str;
  cin >> str;
  if(n == 12){
    if(str[0] > '1' && str[1] <= '2') str[0] = '1';
    if(str[0] > '1' && str[1] > '2') str[0] = '0';
    if(str[0] == '1' && str[1] > '2') str[1] = '0';
    if(str[0] == '0' && str[1] == '0') str[1] = '1';
    if(str[3] > '5') str[3] = '0';
  }
  else {
    if(str[0] > '2') str[0] = '0';
    if(str[0] == '2' && str[1] >= '4') str[1] = '0';
    if(str[3] > '5') str[3] = '0';
  }
  cout << str << endl;
  return 0;
}
