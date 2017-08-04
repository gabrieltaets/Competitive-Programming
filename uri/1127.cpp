#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  string t;

  map<string, int> ms;

  ms["A"] = 0;
  ms["A#"] = 1;
  ms["Bb"] = 1;
  ms["B"] = 2;
  ms["Cb"] = 2;
  ms["B#"] = 3;
  ms["C"] = 3;
  ms["Db"] = 4;
  ms["C#"] = 4;
  ms["D"] = 5;
  ms["Eb"] = 6;
  ms["D#"] = 6;
  ms["E"] = 7;
  ms["Fb"] = 7;
  ms["F"] = 8;
  ms["E#"] = 8;
  ms["F#"] = 9;
  ms["Gb"] = 9;
  ms["G"] = 10;
  ms["Ab"] = 11;
  ms["G#"] = 11;
  while(1){
    string a, b, c;
    cin >> n >> m;
    if(n+m == 0) break;
    for(int i = 0; i < n; ++i){
        cin >> t;
        a.push_back('A'+ms[t]);
    }
    for(int j = 0; j < m; ++j){
        cin >> t;
        b.push_back(ms[t]);
        c.push_back(0);
    }
    bool flag = false;
    for(int i = 0; i < 12; i++){
      for(int j = 0; j < b.size(); j++){
        c[j] = b[j];
        c[j] += i;
        c[j] %= 12;
        c[j] += 'A';
      }
      if(a.find(c)!=-1){
        flag = true;
        break;
      }
    }
    if(flag) printf("S\n");
    else printf("N\n");
    //ver se algum trecho da igual de a e b
  }
  return 0;
}