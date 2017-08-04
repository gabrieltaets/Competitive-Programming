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

typedef struct {
  int t, k, d, s;
} task;
task tasks[100035];

int main(){
  int n, q;
  cin >> n >> q;
  int server[135];
  memset(server,0,sizeof server);
  for(int i = 0; i < q; i++){
    scanf("%d %d %d",&tasks[i].t,&tasks[i].k,&tasks[i].d);
    tasks[i].s = 0;
    int cont = 0;
    for(int j = 0; j < n; j++){
      if(server[j] <= tasks[i].t) cont++;
    }
    if(cont >= tasks[i].k){
      cont = 0;
      for(int j = 0; j < n; j++){
        if(server[j] <= tasks[i].t){
          server[j] = tasks[i].t+tasks[i].d;
          tasks[i].s += j+1;
          cont++;
        }
        if(cont == tasks[i].k) break;
      }
    }
    else tasks[i].s = -1;
  }
  for(int i = 0; i < q; i++){
    printf("%d\n",tasks[i].s);
  }
	return 0;
}
