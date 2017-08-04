#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, grade, ans = -1, ans2 = -1;
  string id, stud;
  int vet[10];
  cin >> N >> stud;
  for(int i = 0; i < N; i++){
    cin >> id >> grade;
    int j;
    bool flag = false;
    if(id == stud) ans2 = grade;
    for(j = 3; j < id.size(); j++){
      if(id[j] != stud[j] && id[j] != '?') break;
    }
    if(j == id.size()) ans = max(ans,grade);
  }
  if(ans2 != -1) cout << ans2 << endl;
  else cout << ans << endl;
  return 0;
}