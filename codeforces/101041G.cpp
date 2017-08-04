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
  string P;
  while(getline(cin,P) && P != "EOF"){
    string in;
    int badness = 0, n;
    vector<string> T;
    getline(cin,in);
    while(!in.empty()){
      T.pb(in);
      getline(cin,in);
    }
    for(int i = 0; i < T.size(); i++){
      int ini = 0, f;
      while((f = T[i].substr(ini).find(P)) != -1) {
        ini += f;
        badness++;
        ini += P.size();
        if(T[i].size() - ini < P.size()) break;
      }
    }
    cin >> n;
    getchar();
    vector<string> song;
    ii worst(badness,-1), t;
    for(int i = 0; i < n; i++){
      int b = 0;
      song.clear();
      getline(cin,P);
      getline(cin,in);
      while(!in.empty()){
        song.pb(in);
        getline(cin,in);
      }
      for(int i = 0; i < song.size(); i++){
        int ini = 0, f;
        while((f = song[i].substr(ini).find(P)) != -1){
          ini += f + P.size();
          b++;
          if(song[i].size() - ini < P.size()) break;
        }
      }
      t = ii(b,i+1);
      if(t.F > worst.F) worst = t;
    }
    printf("%d\n",worst.S);
  }
  return 0;
}
