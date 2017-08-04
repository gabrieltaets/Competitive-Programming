#include <bits/stdc++.h>

using namespace std;

int root[100030];

struct node{
	int a, b, w;
	node(){};
	node(int _a, int _b, int _w){
		a = _a;
		b = _b;
		w = _w;
	}
	bool operator < (const node a) const{
		return w < a.w;

	}
};

vector<node> graph;

void startset(int n)
{
	for(int i = 0; i < n; ++i)
		root[i] = i;
}

int findset(int x){
	if(root[x] == x)
		return x;
	return root[x] = findset(root[x]);
}

int kruskal( int n ){
	int ret = 0;
	startset(n);
	int maiorpeso = 0;
	int cdd_ligada = n;
	sort(graph.begin(), graph.end());
	for(int i = 0; i < graph.size(); ++i)
	{
		int fx = findset(graph[i].a);
		int fy = findset(graph[i].b);
		if(fx!=fy)
		{
			cdd_ligada--;
			root[fx] = fy;
			maiorpeso = max(maiorpeso, graph[i].w);
		}
		if(cdd_ligada == 1) break;
	}
	return maiorpeso;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--)
	{
		graph.clear();
		int n, m;
		cin >> n >> m;
		startset(n);
		int x, y, z;
		for(int i = 0; i < m; ++i)
		{
			cin >> x >> y >> z;
			x--, y--;
			graph.push_back(node(x,y,z));
		}
		cout << kruskal(n) << endl;
	}
}