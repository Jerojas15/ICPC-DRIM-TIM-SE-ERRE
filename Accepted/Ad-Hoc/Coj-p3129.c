#include <stdio.h>

int main(){
	int T,N,P, temp,i, cont, cont2;
	char S[4];
	scanf("%i", &T);
	while(T-->=1){
		scanf("%i %s %i", &N, S, &P);
		if(S[0] == 'e'){
			printf("%i\n", P*2-1);
		}else{
			printf("%i\n", P*2);
		}
	}
	return 0;
}