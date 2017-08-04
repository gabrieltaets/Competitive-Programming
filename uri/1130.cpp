#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(scanf("%d",&n) && n){
    string tab;
    cin >> tab;
    tab = "." + tab + ".";
    int x = 0, d = 0;
    priority_queue<pair<int,int> > pq;
    int cont = 0;
    bool flag = false;
    for(int i = 1; i <= n; i++){
      if(tab[i] == '.') d++;
      else x++;
      if(i > 2 && tab[i-2] == 'X' && tab[i-1] == 'X') flag = true;
      if(i > 2 && tab[i-2] == 'X' && tab[i-1] == '.' && tab[i] == 'X') flag = true;
      if(tab[i-1] == 'X' && tab[i] == '.') cont = 1;
      else if(tab[i] == '.') cont++;
      else if(cont) pq.push(make_pair(cont,i));
    }
    if(n == 4 || flag || (!x && (d&1))) {
      printf("S\n");
      continue;
    }
    else if(!x) {
      printf("N\n");
      continue;
    }
    int move = 0;
    while(!pq.empty()){
      int a = pq.top().first, i = pq.top().second; pq.pop();
      if(a == 2 || a == 3 || a == 4){
        flag = move ? true : false;
        continue;
      }
      pq.push(make_pair(2,i-3));
      pq.push(make_pair(a-3,i));
      tab[i-2] = 'X';
      move = move ? 0:1;
    }
    cout << tab << endl;
    
    if(tab[3] == 'X' && tab[2] == '.' && tab[1] == '.' && !move) printf("S\n");
    else if(tab[n-2] == 'X' && tab[n-1] == '.' && tab[n] == '.' && !move) printf("S\n");
    else if(flag) printf("S\n");
    else printf("N\n");
  }
  return 0;
}