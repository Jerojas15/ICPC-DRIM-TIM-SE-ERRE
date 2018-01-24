#include "stdio.h"
#include "string.h"

int aux1(char x){
	int aux;
	if(x == 'I' ){
		aux = 1;
	}else if(x == 'V' ){
		aux = 5;
	}else if(x == 'X' ){
		aux = 10;
	}else if(x == 'L' ){
		aux = 50;
	}else if(x == 'C' ){
		aux = 100;
	}else if(x == 'D' ){
		aux = 500;
	}else if(x == 'M' ){
		aux = 1000;
	}
	return aux;
}

int main(){
	int N, j;
	int aux,aux2, total = 0;
	char Z[100];
	char *res;
	scanf("%i", &N);
	while(N-->=1){
		scanf("%s", Z);
		for(j = 0;j<strlen(Z);j++){
			aux = aux1(Z[j]);
			if(j<strlen(Z)){
				aux2 = aux1(Z[j+1]);
				if(aux<aux2){
					total += aux2-aux;
					j++;
				}else{
					total += aux;
				}
			}else{
				total += aux;
			}
			
		}
		if(total%3==0){
			res = "YES";
		}else{
			res = "NO";
		}
		printf("%s %i\n", res, total);
		total = 0;
	}
	return 0;
}