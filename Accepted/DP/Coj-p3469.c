#include <stdio.h>
#include <stdlib.h>

int *don;

int main(int argc, char **argv)
{
	int a,b,c,d, i = 1,suma =0,sumaux = 0;
	scanf("%i",&a);
	don = calloc(10000007,sizeof(int));
	while(a--){
		scanf("%i",&d);
		suma+=d;
		for(int j=sumaux;j<=suma;j++){
			don[j] = i;
		}
		don[suma] = i;
		sumaux = suma;
		i++;
	}
	scanf("%i", &b);
	while(b--){
		scanf("%i",&c);
		if(c>suma){
			printf("none\n");
		}else{
			printf("%i\n",(don[c-1]));
		}
	}
	return 0;
}
