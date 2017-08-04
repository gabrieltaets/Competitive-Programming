
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
	int A, B, C;
	scanf("%d %d %d",&A,&B,&C);
	int M;
	if(A >= B && A >= C) M = A;
	if(B >= A && B >= C) M = B;
	if(C >= A && C >= B) M = C;
	printf("%d\n",M);
	return 0;
}
