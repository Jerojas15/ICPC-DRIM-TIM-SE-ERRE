/*uso:
 *rmq.init(n)
 *dfs1(inicial);
 *heavylight(inicial);
 *dfs(); (o poner la llamada adentro de build)
 *rmq[pos[v]] = peso entre dad[v] y v para todo v (aqui se hace como parte de heavylight, si la lista de adjacencia tiene pares(hijo,peso);
 *build(inicial);
 *rmq.updall();
*/
int pos[MAXN], q;//pos[v]=posicion del nodo v en el recorrido de la dfs
//Las cadenas aparecen continuas en el recorrido!
int cantcad;
int homecad[MAXN];//dada una cadena devuelve su nodo inicial
int cad[MAXN];//cad[v]=cadena a la que pertenece el nodo
void heavylight(int v, int cur=-1, int peso = -1){
	if(cur==-1) homecad[cur=cantcad++]=v;
	pos[v]=q++;
	rmq[pos[v]]=peso;
	cad[v]=cur;
	int mx=-1;
	for(int i = 0; i < G[v].size(); i++) if(G[v][i].first!=dad[v])
		if(mx==-1 || treesz[G[v][mx].first]<treesz[G[v][i].first]) mx=i;
	if(mx!=-1) heavylight(G[v][mx].first, cur, G[v][mx].second);
	for(int i = 0; i < G[v].size(); i++) if(i!=mx && G[v][i].first!=dad[v])
		heavylight(G[v][i].first, -1, G[v][i].second);
}
// r = max(query(lca(v,u), v), query(lca(u,v),u));
int query(int an, int v){//O(logn)
	//si estan en la misma cadena:
	if(an == v) return -1;
	if(cad[an]==cad[v] && homecad[cad[an]] == an) return rmq.get(pos[an]+1, pos[v]+1);
	if(cad[an]==cad[v]) return rmq.get(pos[an]+1, pos[v]+1);
	return max(query(an, dad[homecad[cad[v]]]),
			   rmq.get(pos[homecad[cad[v]]], pos[v]+1));
}
