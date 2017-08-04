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
  set<string> s;
  for(int i = 0; i < str.size(); i++){
    string x = str.substr(str.size()-i,i) + str.substr(0,str.size()-i);
    s.insert(x);
  }
  cout << s.size() << endl;
	return 0;
}
