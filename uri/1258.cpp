#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  int n;
  bool mid = false;
  while(cin >> n && n){
    getchar();
    if(mid) cout << endl;
    mid = true;
    vector<string> v[6];
    string str1, str2;
    for(int i = 0; i < n; i++){
      getline(cin,str1);
      getline(cin,str2);
      if(str2 == "branco P") v[0].push_back(str1);
      if(str2 == "branco M") v[1].push_back(str1);
      if(str2 == "branco G") v[2].push_back(str1);
      if(str2 == "vermelho P") v[3].push_back(str1);
      if(str2 == "vermelho M") v[4].push_back(str1);
      if(str2 == "vermelho G") v[5].push_back(str1);
    }
    for(int i = 0; i < 6; i++)
      sort(v[i].begin(),v[i].end());
    for(int i = 0; i < 6; i++){
      for(int j = 0; j < v[i].size(); j++){
        if(i == 0) cout << "branco P ";
        if(i == 1) cout << "branco M ";
        if(i == 2) cout << "branco G ";
        if(i == 3) cout << "vermelho P ";
        if(i == 4) cout << "vermelho M ";
        if(i == 5) cout << "vermelho G ";
        cout << v[i][j] << endl;
      }
    }
  }
  return 0;
}