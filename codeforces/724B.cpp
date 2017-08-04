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

int n, m;

void show(vi v[20]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%d ",v[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

bool check(vi x[20]){
  //show(x);
  for(int i = 0; i < n; i++){
    int dif = 0;
    for(int j = 0; j < m; j++){
      if(x[i][j] != j+1) dif++;
    }
    if(dif > 2) return false;
  }
  return true;
}

int main(){
  cin >> n >> m;
  int tab[30][30];
  vi v[20], id[20];
  for(int i = 0; i < n; i++){
    v[i].resize(m);
    id[i].resize(m);
    for(int j = 0; j < m; j++){
      v[i][j] = id[i][j] = j+1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int x;
      scanf("%d",&x);
      v[i][j] = x;
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      bool ans = true;
      vi x[20];
      for(int k = 0; k < n; k++){
        x[k] = v[k];
      }
      for(int k = 0; k < n; k++){
        swap(x[k][i],x[k][j]);
      }
      ans &= check(x);
      if(ans){
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
