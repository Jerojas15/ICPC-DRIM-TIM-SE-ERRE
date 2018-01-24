#include <stdio.h>

int main(){
	char S[30], L[30];
	int N,Ra,K, R, aux;
	double W, We, prom = 0;

	scanf("%s %i", S, &N);
	aux = N;
	printf("Tournament: %s\n", S);
	printf("Number of players: %i\n", N);
	printf("New ratings:\n");
	while(aux-->0){
		scanf("%s %i %lf %lf %i", L, &Ra, &W, &We, &K);
		R = Ra+K*(W-We);
		prom += Ra;
		printf("%s %i\n", L, R);
	}
	prom = prom / N;
	aux = prom+0.5;
	printf("Media Elo: %i\n", aux);
	return 0;
}