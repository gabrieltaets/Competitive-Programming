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
char in[1000010], de[1000010];
int main(){
  in[0] = de[0] = '\0';
  scanf("%s",in);
  for(int i = 0; i < strlen(in); i++){
    if(in[i] == '.') {
      strcpy(de,in+1+i);
      in[i] = '\0';
      break;
    }
  }
  int szin = strlen(in), szde = strlen(de), szstin, szstde;
  char *startin = in, *startde = de;
  for(int i = 0; i <= szin; i++){
    if(in[i] != '0'){
      szstin = szin-i;
      startin = in+i;
      break;
    }
  }
  for(int i = szde-1; i >= -1; i--){
    if(i == -1){
      szde = 0;
      de[0] = '\0';
      break;
    }
    if(de[i] != '0') {
      szde = i+1;
      de[i+1] = '\0';
      break;
    }
  }
  int cont = szstin-1;
  if(szstin == 0){
    for(int i = 0; i < szde; i++){
      if(de[i] != '0'){
        cont = i+1;
        startde = de+i+1;
        szstde = szde-i-1;
        break;
      }
    }
    printf("%c",*(startde-1));
    if(szstde!=0)
      printf(".%s",startde);
    printf("E-%d\n",cont);
    return 0;
  }
  if(szde==0){
    for(int i = szstin-1; i >= 0; i--){
      if(startin[i] != '0'){
        szstin = i+1;
        startin[i+1] = '\0';
        break;
      }
    }
  }
  printf("%c",*startin);
  if(szstin-1+szde != 0)
    printf(".%s%s",startin+1,de);
  if(cont != 0) printf("E%d",cont);
  printf("\n");
  return 0;
}
