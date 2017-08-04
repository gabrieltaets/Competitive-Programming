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
int main(){
  int T;
  cin >> T;
  char c[] = {'A', 'E', 'I', 'O', 'S'};
  set<char> s(c,c+5);
  while(T--){
    string str;
    cin >> str;
    int sum = 1;
    for(int i = 0; i < str.size(); i++){
      sum *= 2+s.count(str[i]);
    }
    cout << sum << endl;
  }
  return 0;
}
