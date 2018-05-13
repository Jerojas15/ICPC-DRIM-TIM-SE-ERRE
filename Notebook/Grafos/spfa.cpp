#include<bits/stdc++.h>
using namespace std;
typedef pair<unsigned, unsigned> pi;
typedef vector<unsigned> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvpi;

vvpi graph;
//resultados en d
int spfa(int s){
	v d(graph.size(), -1 - max_weight);
	v is_in(graph.size());
	d[s] = 0;

	queue<int> q;
	q.push(s);
	is_in[s] = 1;
	while(!q.empty()){
		int curr = q.front();
		is_in[curr] = 0;
		for(auto i : graph[curr]){
			int w = i.second;			
			int nodo = i.first;

			if((d[curr] + w) < d[nodo]){
				d[nodo] = (d[curr] + w);
				if(!is_in[nodo]){
					is_in[nodo] = 1;
					q.push(nodo);
				}
			}
		}
	}
}
