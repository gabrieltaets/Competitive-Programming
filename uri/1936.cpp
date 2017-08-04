#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
int main(){
  ll fat[20];
  fat[0] = 1;
  for(int i = 1; i < 20; i++) fat[i] = i*fat[i-1];
  int n;
  cin >> n;
  int cont = 0;
  for(int i = 19; i >= 0; i--){
    while(fat[i] <= n){
      cont++;
      n -= fat[i];
    }
  }
  cout << cont << endl;
  return 0;
}