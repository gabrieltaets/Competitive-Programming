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
vector<string> depth[1000035];
char str[1000035];
int maxd = 1;
void read(int d){
  maxd = max(maxd,d);
  int qtd;
  scanf("%[^,],%d",str,&qtd);
  //printf("Read %s %d\n",str,qtd);
  depth[d].pb(string(str));
  for(int i = 0; i < qtd; i++){
    getchar();
    read(d+1);
  }
}
int main(){
  while(1){
    read(1);
    if(getchar() != ',') break;
  }
  printf("%d\n",maxd);
  for(int i = 1; i <= maxd; i++){
    for(int j = 0; j < depth[i].size(); j++){
      cout << depth[i][j] << " ";
    }
    cout << endl;
  }
	return 0;
}
