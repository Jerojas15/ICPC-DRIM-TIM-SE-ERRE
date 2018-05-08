#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

vvi graph;
vi seen;
int a;
int ca,cb;
bool can;

void solve(int i, int color){
	int ncolor;
	if(seen[i]){
		if(!(seen[i] & color)) can = 0;
		return;
	}
	else{
		seen[i] =  color;
		if(color & 1){
			ca ++;
			ncolor = 2;
		}
		else{
			cb++;
			ncolor = 1;
		}
		for(auto j:graph[i]){
			solve(j, ncolor);
		}
		return;
	}
}


int main(void){
	int t;
	cin>>t;
	while(t--){
		can = 1;
		a = 0;
		int v,e;
		cin>>v>>e;
		graph = vvi(v);
		seen = vi(v);
		while(e--){
			int x,y;
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		for(int i = 0; i < v; i++){
			if(seen[i]) continue;
			ca = cb = 0;
			solve(i, 1);	
			if(!ca) a += cb;
			else if(!cb) a += ca;
			else a += min(ca,cb);
		}
		if(can) cout<<a<<'\n';
		else cout<<"-1\n";
	}
	return 0;
}
