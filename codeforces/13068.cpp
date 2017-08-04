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
char str[100100], *ans, base[50050];
int main(){
  int n, sz;
  scanf("%d",&n);
  string C;
  while(n--){
    int res;
    cin >> C;
    sz = C.size();
    for(int i = 0; i <= sz; i++) base[i] = 'z'+1;
    base[sz] = '\0';
    ans = base;
    strcpy(str,(C+C).c_str());
    for(int i = 0; i < sz; i++){
      if(strncmp(str+i,ans,sz) < 0){
        ans = str+i;
        res = i+1;
      }
    }
    cout << res << endl;
  }
  return 0;
}
