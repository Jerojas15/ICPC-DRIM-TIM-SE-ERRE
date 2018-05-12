//toma indice de raiz
//ance es arreglo inicializado a 0
//join y find son union find
//tree es lista de adjacencia 
void lca(int i){
	ance[find(i)] = i;
	for(auto j:tree[i]){
		lca(j);
		join(i,j);
		ance[find(i)] = i;
	}
	seen[i] = 1;	
	
	for(int j = 2*i; j <= n; j += i){
		if(seen[j]); //lca(i,j) = ance[find(j)]
		else; //si no seen, se encontrara cuando j sea procesado
	}
}
