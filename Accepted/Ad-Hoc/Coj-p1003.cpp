#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int T,N,M, i, aux, j, cont;
	cin >> T;
	while(T--){
		cin >> N >> M;
		vector<int> v(N,0);
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
			scanf("%i", &aux);
			v[j] = v[j]+aux;				
			}

		}
		aux = v[0];
		cont = 0;
		for (i = 1; i < N; i++)
		{
			if(aux<v[i]){
				aux = v[i];
				cont = i;
			}
		}
		cout << cont+1 << endl;
		
	}

	return 0;
}