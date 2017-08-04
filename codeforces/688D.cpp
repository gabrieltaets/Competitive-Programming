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
vi v;
void factorize(int n) {
  v.clear();
  int sq = (int)sqrt((double)n);
  for (int i = 2; i <= sq; i++) {
    if (n % i) continue;
    v.pb(i);
    n /= i--;
    sq = (int)sqrt((double)n);
  }
  if (n > 1) v.push_back(n);
}
int must_have[1000010], has[1000010];
int main(){
  int n, k;
  cin >> n >> k;
  bool ans = true;
  factorize(k);
  for(int i = 0; i < 1000010; i++) has[i] = must_have[i] = 0;
  for(int i = 0; i < v.size(); i++) must_have[v[i]]++;
  for(int i = 0; i < n; i++){
    int c;
    scanf("%d",&c);
    factorize(c);
    for(int j = 0; j < v.size(); j++) has[v[j]]++;
    if(k == c) {
      printf("Yes\n");
      return 0;
    }
  }
  for(int i = 0; i < 1000010; i++){
    if(must_have[i] > has[i]){
      ans = false;
      break;
    }
  }
  printf("%s\n",ans?"Yes":"No");
  return 0;
}