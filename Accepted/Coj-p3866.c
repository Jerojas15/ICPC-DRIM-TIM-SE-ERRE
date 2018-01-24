#include <stdio.h>

int main()
{
	unsigned int N, aux,c;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		c = 1;
		scanf("%d", &aux);
		while(aux>1){
			aux/=2;
			
			c++;
		}
		if(aux==0)c=0;
		printf("%d\n", c);
	}
	
	return 0;
}