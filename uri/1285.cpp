#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int N, M, sum = 0;
  int q[5010];
  q[0] = 0;
  for(int i = 1; i <= 5000; i++){
    string str = to_string(i);
    set <char> s;
    for(int j = 0; j < str.size(); j++) s.insert(str[j]);
    if(s.size() == str.size()) sum++;
    q[i] = sum;
  }
  while(cin >> N >> M){
    cout << q[M] - q[N-1] << endl;
  }
  return 0;
}