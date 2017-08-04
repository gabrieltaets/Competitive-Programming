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
  string str;
  while(cin >> str){
    int s1 = 0, s2 = 0, s3 = 0, cont = 0;
    for(int i = 0; i < str.size()-2; i++){
      if(!isdigit(str[i])) continue;
      cont++;
      //printf("At %c\n",str[i]);
      s1 += str[i] - '0';
      //printf("%d += %d*%d\n",s2,str[i]-'0',i+1);
      s2 += (str[i]-'0')*(cont);
      s3 += (str[i]-'0')*(10-cont);
    }
    //printf("s2 = %d s3 = %d\n",s2,s3);
    s2 = (s2%11)%10;
    s3 = (s3%11)%10;
    //printf("must end with %d%d\n",s2,s3);
    if(s2 == str[str.size()-2]-'0' && s3 == str[str.size()-1]-'0') printf("CPF valido\n");
    else printf("CPF invalido\n");
  }
  return 0;
}
