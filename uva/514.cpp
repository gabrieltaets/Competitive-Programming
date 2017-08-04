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
	while(scanf("%d",&n) && n){
		int a[n];
		while(scanf("%d",&a[0]) && a[0]){
			for(int i = 1; i < n; i++){
				scanf("%d",&a[i]);
			}
			stack<int> st;
			int top = 0;
			for(int i = 1; i <= n; i++){
				st.push(i);
				while(!st.empty() && st.top() == a[top]){
					top++;
					st.pop();
				}
			}
			printf("%s\n",top == n ? "Yes":"No");
		}
		printf("\n");
	}
	return 0;
}
