#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n;
	while(scanf("%d",&n) != EOF && n){
		char entrou[n], c;
		stack<char> pilha;
		queue<char> fila;
		string res;
		for(int i = 0; i < n; i++){
			scanf(" %c",&entrou[i]);
		}
		for(int i = 0; i < n; i++){
			scanf(" %c",&c);
			fila.push(c);
		}
		for(int i = 0; i < n; i++){
			pilha.push(entrou[i]);
			res.pb('I');
			while(!pilha.empty() && !fila.empty() && 
				pilha.top() == fila.front() ){
				pilha.pop();
				fila.pop();
				res.pb('R');
			}
		}
		cout << res;
		if(!pilha.empty() || !fila.empty()) printf(" Impossible");
		printf("\n");
	}
	return 0;
}
