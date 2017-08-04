#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define MAXN 40
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

map<string,int> nome;
string rev[MAXN];
stack<int> st;
bool cycle;
int vis[MAXN], n;
vi graph[MAXN];

void dfs(int node){
  vis[node] = 1;
  //printf("Dfs[%s]\n",rev[node].c_str());
  for(int i = 0; i < graph[node].size(); i++){
    int x = graph[node][i];
    if(!vis[x]) dfs(x);
    else if(vis[x] == 1) {
      cycle = true;
      //printf("Found cycle: %s and %s\n",rev[node].c_str(),rev[x].c_str());
    }
  }
  st.push(node);
  vis[node] = 2;
}

bool solve(){
  memset(vis,0,sizeof vis);
  cycle = false;
  dfs(0);
  st.pop();
  for(int i = 1; i <= n; i++) if(vis[i] != 2) return false;
  return !cycle;
}

int main(){
  int teste = 1;
  while(scanf("%d",&n)!=EOF && n){
    
    for(int i = 0; i <= n; i++) graph[i].clear();
    while(!st.empty()) st.pop();
    nome.clear();
    
    for(int i = 1; i <= n; i++){
      string str;
      cin >> str;
      nome[str] = i;
      rev[i] = str;
    }
    for(int i = 1; i <= n; i++){
      string str;
      cin >> str;
      int m;
      cin >> m;
      if(!m){
        graph[0].pb(nome[str]);
      }
      while(m--){
        string r;
        cin >> r;
        graph[nome[r]].pb(nome[str]);
      }
    }
    printf("Teste %d\n",teste++);
    if(solve()){
      //printf("Returned true\n");
      while(!st.empty()){
        cout << rev[st.top()] << " ";
        st.pop();
      }
      cout << endl;
    }
    else {
      cout << "impossivel\n";
    }
  }
  return 0;
}

