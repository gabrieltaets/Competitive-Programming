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
	cin >> n;
	char home[10];
	scanf("%s",home);
	getchar();
	char orig[10], dest[10];
	int o = 0, d = 0;
	for(int i = 0; i < n; i++){
		scanf("%[^-]->%s",orig,dest);
		getchar();
		if(!strcmp(home,orig)) o++;
		if(!strcmp(home,dest)) d++;
	}
	if(o == d) printf("home\n");
	else printf("contest\n");
	return 0;
}
