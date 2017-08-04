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
string answer;
int main(){
  int n, cont = 0;
  cin >> n;
  priority_queue<int,vi,greater<int> > pq;
  while(n--){
    char op[30];
    int val;
    scanf("%s",op);
    if(!strcmp(op,"insert")){
      cin >> val;
      pq.push(val);
      answer += "insert " + to_string(val);
      answer.pb('\n');
      cont++;
    }
    else if(!strcmp(op,"getMin")){
      scanf("%d",&val);
      while(!pq.empty() && pq.top() < val){
        answer += "removeMin";
        answer.pb('\n');
        cont++;
        pq.pop();
      }
      if(pq.empty() || pq.top() > val){
        pq.push(val);
        answer += "insert " + to_string(val);
        answer.pb('\n');
        answer += "getMin " + to_string(val);
        answer.pb('\n');
        cont += 2;
      }
      else {
        cont++;
        answer += "getMin " + to_string(val);
        answer.pb('\n');
      }
    }
    else if(!strcmp(op,"removeMin")){
      cont++;
      if(pq.empty()){
        answer += "insert 0";
        answer.pb('\n');
        cont++;
        pq.push(0);
      }
      pq.pop();
      answer += "removeMin\n";
    }
  }
  printf("%d\n%s",cont,answer.c_str());
  return 0;
}
