#include <stdio.h>
int main(){
	int N, res;
	scanf("%i", &N);
	res = N-(((N-1)/3)+1);
	printf("%i\n", res);
	return 0;
}