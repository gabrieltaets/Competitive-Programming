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

int n;
ll qmx;
ll strength[300010];
vi neigh[300010];
map<ll,ll> freq;
ll maxs = -1e9;
ll ans;

void solve(int s){
	map<ll,ll> freq2(freq.begin(),freq.end());
	if(strength[s] >= maxs-2) {
		freq2[strength[s]-2]++;
		freq2[strength[s]]--;
	}
	for(int i = 0; i < neigh[s].size(); i++){
		int x = neigh[s][i];
		if(strength[x] >= maxs-1){
			freq2[strength[x]-1]++;
			freq2[strength[x]]--;
		}
	}
	if(freq2[maxs]) ans = min(ans,maxs);
	else if(freq2[maxs-1]) ans = min(ans,maxs-1);
	else ans = min(ans,maxs-2);	
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%lld",&strength[i]);
		strength[i] += 2;
		maxs = max(maxs,strength[i]);
	}
	ans = maxs;
	for(int i = 0; i < n; i++){
		if(strength[i] >= maxs - 2) freq[strength[i]]++;
	}
	int u, v;
	for(int i = 1; i < n; i++){
		scanf("%d %d",&u,&v);
		u--; v--;
		neigh[u].pb(v);
		neigh[v].pb(u);
	}
	for(int i = 0; i < n; i++){
		solve(i);
	}
	printf("%lld\n",ans);
	
	return 0;
}
