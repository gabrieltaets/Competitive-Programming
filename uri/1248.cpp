#include <bits/stdc++.h>
using namespace std;

string dieta, manha, almoco;

void manipula_string(){
  bool flag = true;
  for(int i = 0; i < manha.size(); i++){
    int found = dieta.find(manha[i]);
    if(found == -1){
      flag = false;
      break;
    }
    dieta.erase(dieta.begin()+found);
  }
  for(int i = 0; i < almoco.length(); i++){
    int found = dieta.find(almoco[i]);
    if(found == -1){
      flag = false;
      break;
    }
    dieta.erase(dieta.begin()+found);
  }
  sort(dieta.begin(),dieta.end());
  if(flag) cout << dieta << endl;
  else cout << "CHEATER\n";
}

void frequency_table(){
  int freq[200];
  memset(freq,0,sizeof freq);
  bool flag = true;
  for(int i = 0; i < dieta.size(); i++) freq[dieta[i]]++;
  for(int i = 0; i < manha.size(); i++) if(--freq[manha[i]] < 0) flag = false;
  for(int i = 0; i < almoco.size(); i++) if(--freq[almoco[i]] < 0) flag = false;
  if(!flag) cout << "CHEATER";
  else for(int i = 'A'; i <= 'Z'; i++) if(freq[i]) cout << (char)i;
  cout << endl;
}

int main(){
  int N; 
  scanf("%d ",&N);
  while(N--){
    getline(cin,dieta);
    getline(cin,manha);
    getline(cin,almoco);
    //manipula_string();
    frequency_table();
  }
  return 0;
}