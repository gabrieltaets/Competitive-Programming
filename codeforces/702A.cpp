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
  int N;
  cin >> N;
  int V[N];
  for(int i = 0; i < N; i++) cin >> V[i];
  int maxlen=1, lo=0, hi=0, len;
  for(int i = 1; i < N; i++){
    if(V[i] > V[i-1]){
      hi++;
      continue;
    }
    len = hi-lo+1;
    maxlen = max(maxlen,len);
    lo = hi = i;
  }
  len = hi-lo+1;
  maxlen = max(maxlen,len);
  cout << maxlen << endl;
  return 0;
}
