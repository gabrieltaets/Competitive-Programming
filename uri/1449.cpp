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
	int T;
	scanf("%d",&T);
	while(T--){
		int n, m;
		scanf("%d %d",&m,&n);
		getchar();
		map<string, string> mapa;
		for(int i = 0; i < m; i++){
			string a, b;
			getline(cin, a);
			getline(cin, b);
			mapa[a] = b;
		}
		for(int i = 0; i < n; i++){
			char str[100];
			bool flag = false;
			while(scanf("%[^ \n]",str)){
				if(flag) printf(" ");
				flag = true;
				string a(str);
				map<string, string>::iterator it = mapa.find(a);
				if(it == mapa.end()) printf("%s",str);
				else printf("%s",it->S.c_str());
				if(getchar() == '\n') break;
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
