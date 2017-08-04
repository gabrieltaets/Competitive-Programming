#include <bits/stdc++.h>
using namespace std;

string trim(string& str){
  int i;
  for(i = 0; i < str.size() ; i++)
    if(str[i] != '0') break; 
  return str.substr(i);
}

int count(string& str){
  int cont = 0;
  for(int i = 0; i < str.size(); i++) if(str[i] == '0') cont++;
  return cont;
}

long long value(string &str){
  long long val = 0LL;
  int bit;
  for(int i = 0; i < str.size(); i++){
    bit = str.size() - 1 - i;
    if(str[i] == '1') val |= (1LL << bit);
  }
  return val;
}

int main(){
  long long int a, b, j, k, c;
  cin >> a >> b;
  char stra[65], strb[65];
  for(int i = 0; i < 64; i++){
    j = i;
    stra[i] = (a & (1LL << j)) ? '1' : '0';
    strb[i] = (b & (1LL << j)) ? '1' : '0';
  }
  stra[64] = strb[64] = '\0';
  string strMin(stra), strMax(strb);
  reverse(strMin.begin(), strMin.end());
  reverse(strMax.begin(), strMax.end());
  strMin = trim(strMin);
  strMax = trim(strMax);
  
  j = count(strMin);
  if(!strMin.compare(strMax)){
    if(j == 1){
      printf("1\n");
      return 0;
    }
    else {
      printf("0\n");
      return 0;
    }
  }
  if(j == 0){
    strMin = "1" + strMin;
    for(int i = 1; i < strMin.size(); i++)
      strMin[i] = '0';
  }
  j = count(strMin);
  k = strMin.size() - 1;
  while(j > 1){
    if(strMin[k] == '0'){
      strMin[k] = '1';
      j--;
    }
    k--;
  }
  if(value(strMin) > b){
    printf("0\n");
    return 0;
  }
  c = 0;
  //cout << strMin << endl;
  while(value(strMin) <= b){
    if(!next_permutation(strMin.begin(),strMin.end())) strMin = "1" + strMin;
    c++;
    //cout << strMin << endl;
  }
  printf("%d\n",c);
  return 0;
}