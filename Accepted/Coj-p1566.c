# include <stdio.h>

int main(){
	int N;
	scanf("%i", &N);
	while(N!= 0){
		printf("%i\n", (N*(N+1)*(2*N+1))/6);
		scanf("%i", &N);
	}
	return 0;
}