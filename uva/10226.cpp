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
	int T, flag = 0;
	scanf("%d",&T);
	getchar();
	getchar();
	while(T--){
		if(flag) printf("\n");
		flag = 1;
		string str;
		map<string, int> m;
		int cont = 0;
		while(getline(cin,str) && !str.empty()){
			m[str]++;
			cont++;
		}
		map<string, int>::iterator it;
		for(it = m.begin(); it != m.end(); it++){
			printf("%s %.4lf\n",it->F.c_str(),100.0*it->S/cont);
		}
	}
	return 0;
}
