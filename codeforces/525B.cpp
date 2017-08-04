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

int swp[200100];
int main(){
  string str;
  cin >> str;
  memset(swp,0,sizeof swp);
  int n;  
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    int a;
    scanf("%d",&a);
    swp[a-1]++;
  }
  for(int i = 1; i < str.size(); i++){
    swp[i] += swp[i-1];
  }
  for(int i = 0; i < str.size()/2; i++){
    if(swp[i]&1){
      swap(str[i],str[str.size()-i-1]);
    }
  }
  cout << str << endl;
  return 0;
}
