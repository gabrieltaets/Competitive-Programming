#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int freq[300];
int main(){
  int n;
  string s;
  memset(freq,0,sizeof freq);
  cin >> n >> s;
  if(n % 4 != 0){
    printf("===\n");
    return 0;
  }
  for(int i = 0; i < n; i++){
    freq[s[i]]++;
    if(s[i] == '?') continue;
    if(freq[s[i]] > n/4){
      printf("===\n");
      return 0;
    }
  }
  for(int i = 0; i < n; i++){
    if(s[i] == '?'){
      if(freq['A'] < n/4){
        freq['A']++;
        s[i] = 'A';
        continue;
      }
      if(freq['G'] < n/4){
        freq['G']++;
        s[i] = 'G';
        continue;
      }
      if(freq['C'] < n/4){
        freq['C']++;
        s[i] = 'C';
        continue;
      }
      if(freq['T'] < n/4){
        freq['T']++;
        s[i] = 'T';
        continue;
      }
    }
  }
  cout << s << endl;
	return 0;
}
