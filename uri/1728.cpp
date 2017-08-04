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
  char buffer1[10], buffer2[10], buffer3[10];
  while(scanf("%[^+]+%[^=]=%s",buffer1,buffer2,buffer3)!=EOF){
    string str1(buffer1), str2(buffer2), str3(buffer3);
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    reverse(str3.begin(),str3.end());
    int x = stoi(str1), y = stoi(str2), z = stoi(str3);
    if(x+y==z) printf("True\n");
    else printf("False\n");
    if(!x && !y && !z) break;
  }
  return 0;
}
