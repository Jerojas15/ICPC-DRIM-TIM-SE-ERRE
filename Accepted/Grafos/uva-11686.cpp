#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph;
vi color;
vi path;
bool possible;

void solve(int i){
	if(color[i] == 1){
		possible = 0;
		return;
	}
	else if(color[i] == 2) return;
	else{
		color[i] = 1;

		for(auto i: graph[i]) solve(i);

		path.push_back(i);
		color[i] = 2;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>a>>b;
	while(a && b){
		graph = vvi(a+1);
		color = vi(a+1);
		path = vi();
		possible = 1;
		int x,y;
		while(b--){
			cin>>x>>y;
			graph[y].push_back(x);
		}
		for(int i = 1; i <= a; i++){
			solve(i);
		}
		if(possible) for(auto i:path) cout<<i<<'\n';
		else cout<<"IMPOSSIBLE\n";
		cin>>a>>b;
	}

	return 0;
}
