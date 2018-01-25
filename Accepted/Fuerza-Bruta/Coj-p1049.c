#include <stdio.h>

int main(){
	long long int N, k;
	scanf("%lli", &N);
	if(N>=0){
		k = (N*(N+1))/2;
	}else{
		k = (((N*-1)*((N*-1)+1)/2)*-1)+1;
	}

	printf("%lli\n", k);
	return 0;
}