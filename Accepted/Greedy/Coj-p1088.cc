#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int a;
	while(scanf("%d", &a) != EOF){
		double lista[a];
		int i = 0, aux = a, cont = 1, aux2;
		while(a--){
			cin >> lista[i++];
		}
		sort(lista,lista+aux); 
		lista[0]+=1;
		aux2 = 0;
		for(i = 1;i<aux;i++){
			if(lista[i] > lista[aux2]){
				cont++;
				lista[i]+=1;
				aux2 = i;
			}
		}
		cout << cont << endl;
	}


	return 0;
}