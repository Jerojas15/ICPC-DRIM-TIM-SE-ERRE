#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;




int T, N, a, b, depth, bestNode;
vvi graph;
vi visited;
stack<pii> sii;

void dfs(int u, int d){
    visited[u] = 1;
    
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v, d+1);
        }
    }
    if(d>=depth){
        bestNode = u;
        depth = d;
    }
}

int main(){

    scanf("%d",&T);
    
    while(T--){
        
        scanf("%d",&N);
        
        graph = vvi(N+1, vi());
        visited = vi(N+1, 0);
        for(int i = 0; i < N-1; i++){
            scanf("%d %d", &a , &b);
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        bestNode = 0;
        depth = -1;
        dfs(0,1);
        
        visited = vi(N+1, 0);
        depth = -1;
        dfs(bestNode, 1);
        
        printf("%d\n", depth);
    }

    return 0;
}
