#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
  string str;
  while(getline(cin,str)){
    char word = tolower(str[0]), pword = -1;
    int cont = 0;
    for(int i = 0; i < str.size(); i++){
      if(str[i] == ' '){
        if(tolower(str[i+1]) == word && tolower(str[i+1]) != pword){
          cont++;
        }
        pword = word;
        word = tolower(str[i+1]);
      }
    }
    cout << cont << endl;
  }
  return 0;
}