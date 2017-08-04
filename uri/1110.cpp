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
	while(scanf("%d", &n) != EOF && n){
		queue<int> fila;
		for(int i =1; i<=n; i++){
			fila.push(i);
			
		}
		vector<int> desc;
		while(fila.size()>=2){
			desc.pb(fila.front());
			fila.pop();
			fila.push(fila.front());
			fila.pop();
		}
		printf("Discarded cards:");
		for(int i=0; i<desc.size(); i++){
			printf(" %d", desc[i]);
			if(i != desc.size()-1){
				printf(",");
			}
		}
		cout << endl;
		printf("Remaining cards:");
		printf(" %d\n", fila.front());
		
		
	}
	return 0;
}
