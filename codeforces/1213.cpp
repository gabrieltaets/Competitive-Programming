#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    long long x = 1;
    while(x%n!=0) x = x*10+1;
    cout << (int) log10(x)+1 << endl;
  }
}