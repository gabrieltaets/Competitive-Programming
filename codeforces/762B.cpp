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

priority_queue<int, vi, greater<int> > usb, ps2;

int main(){
	int a, b, c, m;
	scanf("%d %d %d %d",&a,&b,&c,&m);
	for(int i = 0; i < m; i++){
		int v;
		string t;
		cin >> v >> t;
		if(t == "USB") usb.push(v);
		else ps2.push(v);
	}
	ll cost = 0, total = 0;
	while(a && !usb.empty()){
		a--;
		total++;
		cost += usb.top();
		usb.pop();
	}
	while(b && !ps2.empty()){
		b--;
		total++;
		cost += ps2.top();
		ps2.pop();
	}
	while(c && (!usb.empty() || !ps2.empty())){
		c--;
		total++;
		if(usb.empty()){
			cost += ps2.top();
			ps2.pop();
		}
		else if(ps2.empty()){
			cost += usb.top();
			usb.pop();
		}
		else {
			if(usb.top() > ps2.top()){
				cost += ps2.top();
				ps2.pop();
			}
			else {
				cost += usb.top();
				usb.pop();
			}
		}
	}
	printf("%lld %lld\n",total,cost);
	return 0;
}
