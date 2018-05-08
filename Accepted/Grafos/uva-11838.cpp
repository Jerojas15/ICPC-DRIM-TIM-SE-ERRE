#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph1, graph2;
vi seen;

int dfs(int i, vvi &graph){
	if(seen[i]) return 0;
	int r = 1;
	seen[i] = 1;
	for(auto a:graph[i]) r += dfs(a, graph);
	return r;
}

int main(void){
	int n,m;
	cin>>n>>m;
	while(n && m){
		graph1 = vvi(n+1);
		graph2 = vvi(n+1);
		while(m--){
			int v,w,p;
			cin>>v>>w>>p;
			if(p == 1){
				graph1[v].push_back(w);
				graph2[w].push_back(v);
			}
			else{
				graph1[v].push_back(w);
				graph2[w].push_back(v);
				graph1[w].push_back(v);
				graph2[v].push_back(w);
			}
		}

		seen = vi(n+1);
		int c1, c2;
		c1 = dfs(1,graph1);
		seen = vi(n+1);
		c2 = dfs(1,graph2);

		cout<<((c1 == n) && (c2 == n)) << '\n';

		cin>>n>>m;
	}

	return 0;
}
